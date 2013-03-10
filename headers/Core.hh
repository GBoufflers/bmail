//
// Core.hh for rush in /home/dell-a_f//projets/suicide
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sun Mar 10 10:47:44 2013 florian dell-aiera
// Last update Sun Mar 10 11:43:52 2013 florian dell-aiera
//

#ifndef	__CORE_HH__
#define	__CORE_HH__


#include	<iostream>
#include	<string>
#include	<fstream>
#include	<algorithm>
#include	<vector>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<cstring>
#include	<sstream>
#include	<unistd.h>
#include	"ICore.hh"

typedef int	SOCKET;
typedef struct	sockaddr_in SOCKADDR_IN;
typedef struct	sockaddr SOCKADDR;

#define		SIZE 4096

class		Core: public ICore
{
  class		Connection
  {
    SOCKET	_sock;
    SOCKADDR_IN	_sin;
    int		_error;
  public:
    Connection();
    virtual	~Connection();
    void	connect_serveur(Core *c);
    int		getError() const;
    SOCKET	getSocket() const;
    SOCKADDR_IN	getSin() const;
  };
  class	Process
  {
  private:
    Connection		p;
    char		buffer[SIZE];
  public:
    Process();
    virtual		~Process();
    virtual bool	sendMail();
    virtual bool	receiveMail(Core *c);
    virtual bool	deleteMail();
    int			read_server(SOCKET sock, char *buffer);
    void		write_server(SOCKET sock, const char *buffer);
  };

  class Parse
  {
  public:
    Parse();
    virtual	~Parse(){};
    void       	parsing(Core *c); 
  };  
  std::string		_Login;
  std::string		_Mdp;
  std::string		_Ip;
  short unsigned int	_Port;
  std::string		_Dest;
  std::string		_Objet;
  std::string		_Message;
  Parse			_parser;
  Process		_process;
  //  Connection		_connect;
public:
  Core();
  virtual		~Core();
  virtual bool		sendMail() const;
  virtual bool		receiveMail();
  virtual bool		deleteMail();
  void			setLogin(const std::string &login) {this->_Login = login;}
  void			setMdp(const std::string &mdp) {this->_Mdp = mdp;}
  void			setIp(const std::string &ip) {this->_Ip = ip;}
  void			setPort(short unsigned int port) {this->_Port = port;}
  void			setDest(const std::string &dest) {this->_Dest = dest;}
  void			setObjet(const std::string &obj) {this->_Objet = obj;}
  void			setMessage(const std::string &message) {this->_Message = message;}
  std::string		getLogin() const {return (this->_Login);}
  std::string		getMdp() const {return(this->_Mdp);}
  std::string		getIp() const {return(this->_Ip);}
  short unsigned int	getPort() const {return(this->_Port);}
  std::string		getDest() const {return(this->_Dest);}
  std::string		getObjet() const {return(this->_Objet);}
  std::string		getMessage() const {return(this->_Message);}
  void			parsing_core();
};

#endif

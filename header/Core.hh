//
// Core.hh for core in /home/dell-a_f//projets/bmail
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sat Mar  9 15:22:58 2013 florian dell-aiera
// Last update Sat Mar  9 20:04:42 2013 florian dell-aiera
//

#ifndef	__CORE_HH__
#define	__CORE_HH__


#include	<fstream>
#include	<iostream>
#include	<string>
#include	<algorithm>
#include	<vector>
#include	<string>
#include	"ICore.hh"

class		Core: public ICore
{
 protected:
  std::string	_Login;
  std::string	_Mdp;
  std::string	_Ip;
  std::string	_Port;
  std::string	_Dest;
  std::string	_Objet;
  std::string	_Message;
 public:
  Core();
  virtual	~Core();
  virtual bool	sendMail() const;
  virtual bool	receiveMail();
  virtual bool	deleteMail();
  void		setLogin(const std::string &login) {this->_Login = login;}
  void		setMdp(const std::string &mdp) {this->_Mdp = mdp;}
  void		setIp(const std::string &ip) {this->_Ip = ip;}
  void		setPort(const std::string &port) {this->_Port = port;}
  void		setDest(const std::string &dest) {this->_Dest = dest;}
  void		setObjet(const std::string &obj) {this->_Objet = obj;}
  void		setMessage(const std::string &message) {this->_Message = message;}
  std::string	getLogin() const {return (this->_Login);}
  std::string	getMdp() const {return(this->_Mdp);}
  std::string	getIp() const {return(this->_Ip);}
  std::string	getPort() const {return(this->_Port);}
  std::string	getDest() const {return(this->_Dest);}
  std::string	getObjet() const {return(this->_Objet);}
  std::string	getMessage() const {return(this->_Message);}
};


#endif

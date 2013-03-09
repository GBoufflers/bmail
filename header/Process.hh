//
// Process.hh for process in /home/dell-a_f//projets/bmail
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sat Mar  9 15:39:33 2013 florian dell-aiera
// Last update Sat Mar  9 23:51:32 2013 florian dell-aiera
//

#ifndef	__PROCESS_HH__
#define	__PROCESS_HH__

#include	"Core.hh"
#include	"Connection.hh"

#define	 SIZE	4096

class	Process: public Core
{
private:
  Connection	p;
  char		buffer[SIZE];
public:
  Process();
  virtual	~Process();
  virtual bool	sendMail();
  virtual bool	receiveMail();
  virtual bool	deleteMail();
  int		read_server(SOCKET sock, char *buffer);
  void		write_server(SOCKET sock, const char *buffer);
};

#endif

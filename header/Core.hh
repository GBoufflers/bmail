//
// Core.hh for core in /home/dell-a_f//projets/bmail
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sat Mar  9 15:22:58 2013 florian dell-aiera
// Last update Sat Mar  9 15:39:00 2013 florian dell-aiera
//

#ifndef	__CORE_HH__
#define	__CORE_HH__

#include	<string>

Class		Core: public ICore
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
};


#endif

//
// Process.hh for process in /home/dell-a_f//projets/bmail
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sat Mar  9 15:39:33 2013 florian dell-aiera
// Last update Sat Mar  9 15:51:04 2013 florian dell-aiera
//

#ifndef	__PROCESS_HH__
#define	__PROCESS_HH__

class	Process: public Core
{
public:
  virtual	sendMail();
  virtual	receiveMail();
  virtual	deleleMail();
}

//
// Core.cpp for rush in /home/dell-a_f//projets/suicide
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sun Mar 10 10:50:33 2013 florian dell-aiera
// Last update Sun Mar 10 11:44:39 2013 florian dell-aiera
//


#include	"../headers/Core.hh"

Core::Core()
{

}


Core::~Core()
{
}

bool	Core::sendMail(Core *core, std::string addr, unsigned short port, std::string From, std::string To, std::string Subject, std::string Text) const
{
  core->_process.sendMail(core, addr, port, From, To, Subject, Text);
  return (true);
}

bool	Core::receiveMail()
{
  //  this->_connect.connect_serveur(this);
  this->_process.receiveMail(this);
  return (true);
}

bool	Core::deleteMail()
{
  return (true);
}

void	Core::parsing_core()
{
  this->_parser.parsing(this);
}

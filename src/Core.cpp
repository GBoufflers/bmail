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

bool	Core::sendMail() const
{
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

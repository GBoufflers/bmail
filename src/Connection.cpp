//
// Connect.cpp for Connect in /home/dell-a_f//projets/bmail
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sat Mar  9 20:32:28 2013 florian dell-aiera
// Last update Sat Mar  9 23:50:10 2013 florian dell-aiera
//

#include	"../header/Connection.hh"

Connection::Connection()
{

}

Connection::~Connection()
{

}

void	Connection::connect_serveur()
{
  this->_sock = socket(AF_INET, SOCK_STREAM, 0);
  this->_sin.sin_addr.s_addr = inet_addr(this->_Ip.c_str());
  this->_sin.sin_family = AF_INET;
  this->_sin.sin_port = htons(this->_Port);
  if (connect(this->_sock, (SOCKADDR*)&(this->_sin), sizeof(this->_sin)) != -1)
    this->_error = 0;
  else
    this->_error = -1;
}

int	Connection::getError() const
{
  return (this->_error);
}


SOCKET	Connection::getSocket() const
{
  return (this->_sock);
}

SOCKADDR_IN Connection::getSin() const
{
  return (this->_sin);
}

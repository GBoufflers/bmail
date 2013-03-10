#include	"../headers/Core.hh"

Core::Process::Process()
{

}

Core::Process::~Process()
{

}

bool	Core::Process::helo(char buff[1024])
{
  char *bitch;

  send(this->_ssock, "HELO CLIENT\n", 12, 0);
  recv(this->_ssock, buff, 1024, 0);
  bzero(buff, 1024);
  return (true);
}

bool	Core::Process::peoples(char buff[1024], std::string From, std::string To)
{
  std::string	f;
  std::string	t;

  f = f + "MAIL FROM: <";
  f = f + From;
  f = f + ">\n";
  t = t + "RCPT TO: <";
  t = t + To;
  t = t + ">\n";
  std::cout << f << std::endl;
  std::cout << t << std::endl;
  send(this->_ssock, f.c_str(), f.size(), 0);
  recv(this->_ssock, buff, 1024, 0);
  bzero(buff, 1024);
  send(this->_ssock, t.c_str(), t.size(), 0);
  recv(this->_ssock, buff, 1024, 0);
  bzero(buff, 1024);
  return (true);
}

bool	Core::Process::data(char buff[1024], std::string Subject, std::string Text)
{
  std::string	t;
  std::string	s;

  s = "Subject: ";
  s = s + Subject;
  s = s + "\n";
  send(this->_ssock, "DATA\n", 5, 0);
  recv(this->_ssock, buff, 1024, 0);
  bzero(buff, 1024);
  send(this->_ssock, s.c_str(), s.size(), 0);
  recv(this->_ssock, buff, 1024, 0);
  bzero(buff, 1024);
  t = Text + "\n.\n";
  send(this->_ssock, t.c_str(), t.size(), 0);
  recv(this->_ssock, buff, 1024, 0);
  bzero(buff, 1024);
  return (true);
}

bool	Core::Process::sendMail(Core *c, std::string addr, unsigned short port, std::string From, std::string To, std::string Subject, std::string Text)
{
  char	buff[1024];

  bzero(buff, 1024);
  this->_ssock = socket(AF_INET, SOCK_STREAM, 0);  
  this->_ssin.sin_addr.s_addr = inet_addr(addr.c_str());
  this->_ssin.sin_family = AF_INET;
  this->_ssin.sin_port = htons(port);
  if(connect(this->_ssock, (SOCKADDR*)&this->_ssin, sizeof(this->_ssin)) != -1)
    {
      this->helo(buff);
      this->peoples(buff, From, To);
      this->data(buff, Subject, Text);
      return (true);
    }
  else
    return (false);
}

bool	Core::Process::receiveMail(Core	*c)
{
  fd_set	rd;
  int		i;

  this->p.connect_serveur(c);
  if (this->p.getError() != -1)
    {
      if (c->getPort() == 110)
	{
	  write_server(this->p.getSocket(), "USER epitech@dualabs.com\n");
	  write_server(this->p.getSocket(), "PASS epitech\n");
	  write_server(this->p.getSocket(), "LIST\n");
	  // write_server(this->p.getSocket(), "quit\n");
	  while (1)
	    {
	      FD_ZERO(&rd);
	      FD_SET(this->p.getSocket(), &rd);
	      if (select(this->p.getSocket() + 1, &rd, NULL, NULL, NULL) < 0)
		{
		  std::cerr << "Error on select" << std::endl;
		  exit(EXIT_FAILURE);
		}
	      if (FD_ISSET(this->p.getSocket(), &rd))
		{
		  i = read_server(this->p.getSocket(), this->buffer);
		  if (i ==0)
		    {
		      std::cout << "Server disconnected" << std::endl;
		      break;
		    }
		  printf("%s\n", this->buffer);
		}
	    }
	  close(this->p.getSocket());
	}
    }
  return (true);
}

  bool	Core::Process::deleteMail()
  {
    return (true);
  }

int	Core::Process::read_server(SOCKET sock, char *buffer)
{
  int	n = 0;

  if ((n = recv(sock, buffer, SIZE - 1, 0)) < 0)
    {
      std::cerr << "Erreur on recv" << std::endl;
      exit(EXIT_FAILURE);
    }
  buffer[n] = 0;
  return (n);
}

void	Core::Process::write_server(SOCKET sock, const char *buffer)
{
  if (send(sock, buffer, strlen(buffer), 0) < 0)
    {
      std::cerr << "Erreur on send()" << std::endl;
      exit(EXIT_FAILURE);
    }
}

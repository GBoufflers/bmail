#include	"../headers/Core.hh"

Core::Process::Process()
{

}

Core::Process::~Process()
{

}

bool	Core::Process::sendMail()
{
  return (true);
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

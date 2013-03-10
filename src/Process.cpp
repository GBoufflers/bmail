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


int	Core::Process::nbr_mail(char *buffer)
{
  int	i;
  int	j;
  char	cpy[SIZE];

  i = 0;
  j = 0;
  cpy[0] = 0;
  while (buffer[i] && buffer[i] != ' ')
    i++;
  i++;
  while (buffer[i] && buffer[i] != ' ')
    cpy[j++] = buffer[i++];
  j = atoi(cpy);
  return (j);
}

bool	Core::Process::receiveMail(Core	*c)
{
  int	nb;
  int	i = 1;
  std::string		retr;
  std::ostringstream	oss;
  std::string		str;
  std::string		in;
  
  retr[0] = 0;
  this->p.connect_serveur(c);
  if (this->p.getError() != -1)
    {
      if (c->getPort() == 110)
      	{
	  read_server(this->p.getSocket(), this->buffer);
	  bzero(this->buffer, SIZE);	  
	  write_server(this->p.getSocket(), "USER epitech@dualabs.com\n");
	  read_server(this->p.getSocket(), this->buffer);
	  bzero(this->buffer, SIZE);
	  write_server(this->p.getSocket(), "PASS epitech\n");
	  read_server(this->p.getSocket(), this->buffer);
	  bzero(this->buffer, SIZE);	  
	  write_server(this->p.getSocket(), "stat\n");
	  read_server(this->p.getSocket(), this->buffer);
	  nb = this->nbr_mail(this->buffer);
	  bzero(this->buffer, SIZE);
	  while (i < nb )
	    {
	      oss << i;
	      str = oss.str();
	      retr = "retr " + str + "\n";
	      write_server(this->p.getSocket(), retr.c_str());
	      read_server(this->p.getSocket(), this->buffer);
	      in.insert(0, this->buffer);
	      this->mail.push_back(in);
	      bzero(this->buffer, SIZE);
	      oss.str("");
	      retr.erase(0, retr.size());
	      in.erase(0, in.size());
	      //	      std::cout << i << std::endl;
	      i++;
	    }
	  write_server(this->p.getSocket(), "quit\n");
	  read_server(this->p.getSocket(), this->buffer);
	  bzero(this->buffer, SIZE);
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

  while (buffer[strlen(buffer) -1] != '\n')
    {
      if (recv(sock, buffer, SIZE - 1, 0) < 0)
	{
	  std::cerr << "Erreur on recv" << std::endl;
	  exit(EXIT_FAILURE);
	}
    }
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

std::list<std::string>	Core::Process::getMail() const
{
  return (this->mail);
}

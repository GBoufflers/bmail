#include	"../headers/Core.hh"

Core::Process::Process()
{

}

Core::Process::~Process()
{

}

bool	Core::Process::sendMail()
{
  char		*bitch;
  char		buff[1024];

  if(!erreur)
    {
      /* Création de la socket */
      sock = socket(AF_INET, SOCK_STREAM, 0);
      /* Configuration de la connexion */
      sin.sin_addr.s_addr = inet_addr("10.42.1.60");
      sin.sin_family = AF_INET;
      sin.sin_port = htons(PORT);
      /* Si le client arrive à se connecter */
      if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
        {
          printf("Connexion à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
          //                                                                                                                                                                                                                                                                                                                  
          send(sock, "HELO CLIENT\n", 12, 0);
          recv(sock, buff, 1024, 0);
          printf("helo = %s", buff);
          //                                                                                                                                                                                                                                                                                                                  
          bitch = strdup("MAIL FROM: <guillaume.boufflers@epitech.eu>\n");
          send(sock, bitch, strlen(bitch), 0);
          recv(sock, buff, 1024, 0);
          printf("mail from = %s", buff);
          //                                                                                                                                                                                                                                                                                                                  
          bitch = strdup("RCPT TO: <guillaume.boufflers@epitech.eu>\n");
          send(sock, bitch, strlen(bitch), 0);
          recv(sock, buff, 1024, 0);
          printf("rcpt to = %s", buff);
          //                                                                                                                                                                                                                                                                                                                  
          bitch = strdup("DATA\n");
          send(sock, bitch, strlen(bitch), 0);
          recv(sock, buff, 1024, 0);
          printf("data = %s", buff);
          //                                                                                                                                                                                                                                                                                                                  
          bitch = strdup("\n");
          send(sock, bitch, strlen(bitch), 0);
          recv(sock, buff, 1024, 0);
          printf("data = %s", buff);
          //                                                                                                                                                                                                                                                                                                                  
          bitch = strdup("bonjour !!\n.\n");
          send(sock, bitch, strlen(bitch), 0);
          recv(sock, buff, 1024, 0);
          printf("data = %s", buff);
        }
      else
        printf("Impossible de se connecter\n");
      /* On ferme la socket précédemment ouverte */
      closesocket(sock);
    }
  return EXIT_SUCCESS;

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

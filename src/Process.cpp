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
	  // write_server(this->p.getSocket(), "retr 2\n");
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

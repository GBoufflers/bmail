#ifndef		__CONNECTION_HH__
#define		__CONNECTION_HH__

#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	"Core.hh"

typedef int	SOCKET;
typedef struct	sockaddr_in SOCKADDR_IN;
typedef struct	sockaddr SOCKADDR;

class		Connection: public Core
{
  SOCKET	_sock;
  SOCKADDR_IN	_sin;
  int		_error;
public:
  Connection();
  virtual	~Connection();
  void		connect_serveur();
  int		getError() const;
};

#endif

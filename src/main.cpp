//
// main.cpp for rush in /home/dell-a_f//projets/bmail/src
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sat Mar  9 15:09:19 2013 florian dell-aiera
// Last update Sat Mar  9 22:27:40 2013 florian dell-aiera
//

#include	"../header/Core.hh"
#include	"../header/Parse.hh"
#include	"../header/Connection.hh"

int		main()
{
  Parse		p;
  Connection	t;

  p.parsing();
  t.connect_serveur();
  return (0);
}

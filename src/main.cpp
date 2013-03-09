//
// main.cpp for rush in /home/dell-a_f//projets/bmail/src
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sat Mar  9 15:09:19 2013 florian dell-aiera
// Last update Sat Mar  9 23:55:15 2013 florian dell-aiera
//

#include	"../header/Core.hh"
#include	"../header/Parse.hh"
#include	"../header/Connection.hh"
#include	"../header/Process.hh"

int		main()
{
  Parse		p;
  Process	test;

  p.parsing();
  test.receiveMail();
  return (0);
}

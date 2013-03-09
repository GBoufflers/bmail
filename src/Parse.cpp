//
// Parse.cpp for rush in /home/dell-a_f//projets/bmail/src
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sat Mar  9 20:07:42 2013 florian dell-aiera
// Last update Sat Mar  9 20:23:22 2013 florian dell-aiera
//

#include	"../header/Parse.hh"


Parse::Parse()
{
  
}

void				Parse::parsing()
{
  std::fstream			fichier("server.conf");
  std::string			content;
  int				id;
  const std::string		sub_str = ":";
  std::vector<std::string>	infos;
  int				i = 0;
  
  if (fichier)
    {
      while (getline(fichier, content))
	{
	  if (i == 4)
	    {
	      // set des attributs
	      for (std::vector<std::string>::iterator it = infos.begin(); it < infos.end(); it++)
		std::cout << *it << std::endl;
	    }
	  if ((id = content.find(sub_str, 0)))
	    {
	      id += 2;
	      infos.push_back(content.substr(id, content.size()));
	      i++;
	    }
	}
      fichier.close();
    }
  else
    std::cerr << "Unable to open: server.conf" << std::endl;
}

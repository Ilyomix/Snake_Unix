//
// main.cpp for  in /home/abd-li_i/rendu/cpp_nibbler/core
// 
// Made by ilyes abd-lillah
// Login   <abd-li_i@epitech.net>
// 
// Started on  Sun Apr  6 19:54:06 2014 ilyes abd-lillah
// Last update Sun Apr  6 23:26:26 2014 ilyes abd-lillah
//

#include <cstdlib>
#include <time.h>
#include <sstream>
#include <ctime>
#include "Dlloader.hh"
#include "Snake.hh"
#include "GameManager.hh"

int	isNumerical(std::string const& str)
{
  for (int i = 0; i < str.length(); i++)
    {
      if (str[i] < 48 || str[i] > 57)
	return (-1);
    }
  return (0);
}

int	checkParam(std::string const& height, std::string const& length)
{
  int numb;

  if (isNumerical(height) != 0)
    {
      std::cerr << "Height must be a number." << std::endl;
      return (-1);
    }
  else if (isNumerical(length) != 0)
    {
      std::cerr << "Length must be a number." << std::endl;
      return (-1);
    }
  std::istringstream(height) >> numb;
  if (numb < 5 || numb > 53)
    {
      std::cerr << "Invalid height." << std::endl;
      return (-1);
    }
  std::istringstream(length) >> numb;
  if (numb < 5 || numb > 28)
    {
      std::cerr << "Invalid length." << std::endl;
      return (-1);
    }
  return (0);
}

int	main(int ac, char **av, char **envp)
{
  char *error;
  int length;
  int height;
  bool end = false;
  IDisplayModule *lib;

  if (envp[0] == NULL)
    {
      std::cerr << "No environnement term." << std::endl;
      exit(EXIT_FAILURE);
    }
  srand(time(NULL));
  if (ac != 4)
    {
      std::cerr << "USAGE: ./nibbler width height librarypath" << std::endl;
      exit(EXIT_FAILURE);
    }
  if (!strlen(av[1]) || !strlen(av[2]) || !strlen(av[3]))
    {
      std::cerr << "USAGE: ./nibbler width height librarypath" << std::endl;
      exit(EXIT_FAILURE);
    }
  if (checkParam(av[1], av[2]) == -1)
    exit(EXIT_FAILURE);
  std::istringstream(av[1]) >> height;
  std::istringstream(av[2]) >> length;
  DLLoader *loader = new DLLoader(av[3], height, length);
  if (!loader->getHandler())
    {
      std::cerr << dlerror() << std::endl;
      exit(EXIT_FAILURE);
    }
  GameManager	game(height, length);
  lib = loader->getInstance();

  int	i = 1;
  clock_t time;

  float     sec;
  time = clock();
  while (i != 0)
    {
      time = clock() - time;
      sec = ((float)time) / CLOCKS_PER_SEC;
      if ((int)sec * 40000 % 10000 == 0) 
	{
	  game.display(lib);
	  i = game.moveSnake(lib);
	  if (i == 10)
	    {
	      i = 0;
	      end = true;
	    }
	  lib->refresh();
	}
    }
  if (end == true)
    {
      std::cout << "GAME OVER" << std::endl;
      std::cout << "your score is: " << game.getSnake().size() - 4 << std::endl;
    }
  dlerror();
  delete loader;
  exit(EXIT_SUCCESS);
}

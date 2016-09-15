//
// Snake.hh for  in /home/tardif_a/cpp/nibbler/core
// 
// Made by tardif stephanie
// Login   <tardif_a@epitech.net>
// 
// Started on  Fri Apr  4 17:35:26 2014 tardif stephanie
// Last update Sun Apr  6 20:02:20 2014 ilyes abd-lillah
//

#ifndef _SNAKE_HH_
#define _SNAKE_HH_

#include <iostream>
#include <vector>
#include <string>

class		Snake
{
public:
  Snake(int const&, int const&, int const&);
  virtual ~Snake();
  int	  modifCoord(int const& dir, int const& height, int const& length, int const&, int const&, int const&);
  void	  moveACase();
  void	  followHead(int const&, int const&);
  const int	getX() const;
  const int getY() const;
  const int getDir() const;
private:
  int	_x;
  int	_y;
  int	_dir;
};

#endif

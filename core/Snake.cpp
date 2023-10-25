//
// Snake.cpp for nibbler in /home/tardif_a/cpp/nibbler/core
// 
// Made by tardif stephanie
// Login   <tardif_a@epitech.net>
// 
// Started on  Fri Apr  4 17:42:37 2014 tardif stephanie
// Last update Sun Apr  6 20:01:31 2014 ilyes abd-lillah
//

#include "Snake.hh"

Snake::Snake(int const& x, int const& y, int const& dir)
{
  this->_x = x;
  this->_y = y;
  this->_dir = dir;
}

Snake::~Snake()
{
}

int		Snake::modifCoord(int const& dir, int const& height, int const& length, int const& x, int const& y, int const& i)
{
  if (i == 0)
    {
      switch (dir)
	{
	case 1:
	  switch (this->getDir())
	    {
	    case 1:
	      this->_y -= 1;
	      this->_dir = 4;
	      break;
	    case 2:
	      this->_x += 1;
	      this->_dir = 1;
	      break;
	    case 3:
	      this->_y += 1;
	      this->_dir = 2;
	      break;
	    case 4:
	      this->_x -= 1;
	      this->_dir = 3;
	      break;
	    }
	  break;
	case 2:
	  switch (this->getDir())
	    {
	    case 1:
	      this->_y += 1;
	      this->_dir = 2;
	      break;
	    case 2:
	      this->_x -= 1;
	      this->_dir = 3;
	      break;
	    case 3:
	      this->_y -= 1;
	      this->_dir = 4;
	      break;
	    case 4:
	      this->_x += 1;
	      this->_dir = 1;
	      break;
	    }
	  break;
	default:
	  switch (this->getDir())
	    {
	    case 1:
	      this->_x += 1;
	      break;
	    case 2:
	      this->_y += 1;
	      break;
	    case 3:
	      this->_x -= 1;
	      break;
	    case 4:
	      this->_y -= 1;
	      break;
	    }
	  break;
	}
    }
  else
    {
      this->_y = y;
      this->_x = x;
    }
  if (this->_x < 0 || this->_x >= height || this->_y < 0 || this->_y >= length)
    return (-1);
  return (0);
}

void	Snake::moveACase()
{
  switch (this->getDir())
    {
    case 1:
      this->_x += 1;
      break;
    case 2:
      this->_y += 1;
      break;
    case 3:
      this->_x -= 1;
      break;
      this->_y -= 1;
    case 4:
      break;
    }
}

void	Snake::followHead(int const& x, int const& y)
{
  this->_x = x;
  this->_y = y;
}

const int	Snake::getX() const
{
  return this->_x;
}

const int	Snake::getY() const
{
  return this->_y;
}

const int	Snake::getDir() const
{
  return this->_dir;
}

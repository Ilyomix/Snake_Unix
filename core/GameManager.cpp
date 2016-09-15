//
// GameManager.cpp for  in /home/tardif_a/cpp/nibbler/core
// 
// Made by tardif stephanie
// Login   <tardif_a@epitech.net>
// 
// Started on  Fri Apr  4 17:37:09 2014 tardif stephanie
// Last update Sun Apr  6 17:35:21 2014 alexandre lys
//

#include "GameManager.hh"
#include <unistd.h>

GameManager::GameManager(int height, int length)
{
  int		x = height / 2;
  int		y = length / 2;
  int		dir = 1;
  Snake		snake1(x, y, dir);
  Snake		snake2(x - 1, y, dir);
  Snake		snake3(x - 2, y, dir);
  Snake		snake4(x - 3, y, dir);
  
  this->_height = height;
  this->_length = length;
  this->_snake.push_back(snake1);
  this->_snake.push_back(snake2);
  this->_snake.push_back(snake3);
  this->_snake.push_back(snake4);
  this->putFruit();
}

GameManager::~GameManager()
{
  this->_snake.clear();
}

std::vector<Snake> GameManager::getSnake() const
{
  return this->_snake;
}

int	GameManager::isEating()
{
  int	x;
  int	y;
  int	tmpx;
  int	tmpy;
  
  if (this->_snake[0].getX() == this->_xFruit && this->_snake[0].getY() == this->_yFruit)
    {
      Snake elem(this->_xFruit, this->_yFruit, 1);
      x = this->_xFruit;
      y = this->_yFruit;
      this->_snake.push_back(elem);
      this->_snake[0].moveACase();
      for (int i = 1; i < this->_snake.size(); i++)
	{
	  tmpx = this->_snake[i].getX();
	  tmpy = this->_snake[i].getY();
	  this->_snake[i].followHead(x, y);
	  x = tmpx;
	  y = tmpy;
	}
      return (0);
    }
  return (1);
}

int	GameManager::eatingItself()
{
  int	x = this->_snake[0].getX();
  int	y = this->_snake[0].getY();
  int	i;

  for (i = 3; i < this->_snake.size(); i++)
    {
      if (x == this->_snake[i].getX() && y == this->_snake[i].getY())
      	return (0);
    }
  return (1);
}

int	GameManager::moveSnake(IDisplayModule *lib)
{
  int	dir;
  int	end;
  int	x, y;
  int	tmp_body_x = 0;
  int	tmp_body_y = 0;

  dir = lib->catchKey();
  if (!dir)
    return (0);
  for (size_t i = 0; i < this->_snake.size(); i++)
    {
      x = this->_snake[i].getX();
      y = this->_snake[i].getY();
      end = this->_snake[i].modifCoord(dir, this->_height, this->_length, tmp_body_x, tmp_body_y, i);
      tmp_body_x = x;
      tmp_body_y = y;
      if (end == -1)
	return (10);
      if (this->isEating() == 0)
	this->putFruit();
    }
  usleep(100000);
  if (this->eatingItself() == 0)
    return (10);
  return (dir);
}

void	GameManager::display(IDisplayModule *lib)
{
  for (size_t i = 0; i < this->_snake.size(); i++)
    lib->putSprite(this->_snake[i].getX(), this->_snake[i].getY(), this->_snake[i].getDir(), 0);
  lib->putSprite(this->_xFruit, this->_yFruit, 0, 1);
  lib->update();
}

void	GameManager::putFruit()
{
  int			x;
  int			y;
  int			j;

  j = -1;
  while (j == -1)
    {
      x = (rand() % this->_length);
      y = (rand() % this->_height);
      j = 0;
      for (int i = 0; i < this->_snake.size(); i++)
	{
	  if (x == this->_snake[i].getX() && y == this->_snake[i].getY())
	    j = -1;
	}
      if (x < 2 || x > this-> _height - 2 || y < 2 || y > this->_length - 2)
	j = -1;
    }
  this->_xFruit = x;
  this->_yFruit = y;
}

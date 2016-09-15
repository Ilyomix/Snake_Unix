//
// GameManager.hh for nibbler in /home/tardif_a/cpp/nibbler/core
// 
// Made by tardif stephanie
// Login   <tardif_a@epitech.net>
// 
// Started on  Fri Apr  4 17:32:16 2014 tardif stephanie
// Last update Sun Apr  6 17:15:03 2014 tardif stephanie
//

#ifndef GAMEMANAGER_HH_
#define GAMEMANAGER_HH_

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Snake.hh"
#include "Dlloader.hh"

class		GameManager
{
public:
  GameManager(int height, int lenght);
  virtual ~GameManager();
  std::vector<Snake> getSnake() const;
  void	createMap();
  void	putFruit();
  int	moveSnake(IDisplayModule *);
  void	display(IDisplayModule *);
  int	isEating();
  int	eatingItself();

private:
  int _height;
  int _length;
  int _xFruit;
  int _yFruit;
  std::vector<Snake> _snake;
};

#endif

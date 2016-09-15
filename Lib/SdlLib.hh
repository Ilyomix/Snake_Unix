//
// sdl_part.hh for  in /home/tardif_a/cpp/nibbler/core
// 
// Made by tardif stephanie
// Login   <tardif_a@epitech.net>
// 
// Started on  Fri Apr  4 18:41:23 2014 tardif stephanie
// Last update Sun Apr  6 21:32:15 2014 ilyes abd-lillah
//

#ifndef _SDLLIB_HH_
#define _SDLLIB_HH_

/*********** Includes ***********/

#include "IDisplay.hh"
#include <fstream>
#include <iostream>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

/*********** Classes ***********/

class		SdlLib: public IDisplayModule
{
public:
  SdlLib(int, int);
  virtual ~SdlLib();
public:
  void				draw_map();
  void				my_puterror(std::string const& err) const;
  int				catchKey() const;
  void				refresh();
  void				update();
  void				putSprite(const int &, const int &, const int &, const int &);
  void				displayWall();
private:
  Mix_Chunk			*sound;
  SDL_Surface			*screen;
  SDL_Surface			*wall;
  SDL_Surface			*snake;
  SDL_Surface			*food;
  SDL_Surface			*bkgr;
  int    			_height;
  int		       		_length;
};

/********** Define ***********/

#endif /*!_SDLLIB_HH_*/

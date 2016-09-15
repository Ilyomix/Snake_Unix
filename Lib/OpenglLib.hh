//
// OpenglLib.hh for  in /home/abd-li_i/rendu/cpp_nibbler/sdl
// 
// Made by ilyes abd-lillah
// Login   <abd-li_i@epitech.net>
// 
// Started on  Sun Apr  6 15:33:29 2014 ilyes abd-lillah
// Last update Sun Apr  6 20:26:34 2014 ilyes abd-lillah
//

#ifndef _OPENGLLIB_HH_
#define _OPENGLLIB_HH_

/*********** Includes ***********/

#include "IDisplay.hh"
#include <iostream>
#include <string>
#include <new>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <unistd.h>
/*********** Classes ************/

class		OpenglLib: public IDisplayModule
{
public:
  OpenglLib(int, int);
  virtual ~OpenglLib();
public:
  void		draw_map();
  void		my_puterror(std::string const& err) const;
  int		catchKey() const;
  void		update();
  void		refresh();
  void		putSprite(const int &, const int &, const int &, const int &);
private:
  SDL_Surface	*screen;
  int		lgt;
  int		hgt;
};

#endif /*!_OPENGLLIB_HH_*/

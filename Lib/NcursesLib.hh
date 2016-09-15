//
// Ncurseslib.hh for  in /home/abd-li_i/rendu/cpp_nibbler/ncurses
// 
// Made by ilyes abd-lillah
// Login   <abd-li_i@epitech.net>
// 
// Started on  Sat Apr  5 14:35:39 2014 ilyes abd-lillah
// Last update Sun Apr  6 20:23:06 2014 ilyes abd-lillah
//

#ifndef _NCURSESLIB_HH_
#define _NCURSESLIB_HH_

/*********** Includes ***********/

#include "IDisplay.hh"
#include <iostream>
#include <string>
#include <ncurses/curses.h>
#include <cstdlib>

/*********** Classes ***********/

class		NcursesLib: public IDisplayModule
{
public:
  NcursesLib(int, int);
  virtual ~NcursesLib();
public:
  int			catchKey() const;
  void			my_puterror(std::string const& err) const;
  void			refresh();
  void			update();
  void			putSprite(const int &, const int &, const int &, const int &);
private:
  WINDOW		*screen;  
};

#endif /*!_NCURSESLIB_HH_*/

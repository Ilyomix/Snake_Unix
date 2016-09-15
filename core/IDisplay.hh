//
// IDisplay.hh for  in /home/abd-li_i/rendu/cpp_nibbler/core
// 
// Made by ilyes abd-lillah
// Login   <abd-li_i@epitech.net>
// 
// Started on  Sun Apr  6 20:16:21 2014 ilyes abd-lillah
// Last update Sun Apr  6 20:16:22 2014 ilyes abd-lillah
//

#ifndef IDISPLAY_HH_
#define IDISPLAY_HH_

#include <iostream>

class IDisplayModule
{
public:
  virtual ~IDisplayModule() {}
  virtual int				catchKey() const = 0;
  virtual void				refresh() = 0;
  virtual void				update() = 0;
  virtual void				putSprite(int const&, int const&, int const&, int const&) = 0;
};

#endif

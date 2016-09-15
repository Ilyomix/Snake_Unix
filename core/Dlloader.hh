//
// Dlloader.hh for  in /home/abd-li_i/rendu/cpp_nibbler/core
// 
// Made by ilyes abd-lillah
// Login   <abd-li_i@epitech.net>
// 
// Started on  Sun Apr  6 19:55:32 2014 ilyes abd-lillah
// Last update Sun Apr  6 23:35:02 2014 ilyes abd-lillah
//

#ifndef DLLOADER_HH_
#define DLLOADER_HH_

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "IDisplay.hh"

class DLLoader
{
private:
  void *_handle;
  IDisplayModule *_mod;

 public:
  DLLoader(const std::string &, const int &, const int &);
  ~DLLoader();
  void *getHandler() const;
  IDisplayModule *getInstance() const;

};

#endif

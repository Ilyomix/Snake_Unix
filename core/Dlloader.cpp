//
// Dlloader.cpp for  in /home/tardif_a/rendu/cpp_nibbler/core
// 
// Made by tardif stephanie
// Login   <tardif_a@epitech.net>
// 
// Started on  Sun Apr  6 16:48:38 2014 tardif stephanie
// Last update Sun Apr  6 23:41:18 2014 ilyes abd-lillah
//

#include "Dlloader.hh"

DLLoader::DLLoader(const std::string & lib, int const& height, int const& length)
{
  IDisplayModule *(*func)(int, int);

  
  this->_handle = dlopen(lib.c_str(), RTLD_LAZY);
  if (this->_handle)
    {
      if (dlsym(this->_handle, "init") == NULL)
	exit(0);
      *(void **) (&func) = dlsym(this->_handle, "init");
      this->_mod = (*func)(height, length);
    }
}

DLLoader::~DLLoader()
{
  delete this->_mod;
  dlclose(this->_handle);
}

void	*DLLoader::getHandler() const
{
  return (this->_handle);
}

IDisplayModule *DLLoader::getInstance() const
{
  return this->_mod;
}

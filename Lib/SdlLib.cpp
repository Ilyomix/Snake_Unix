 //
// sdl_part.cpp for  in /home/tardif_a/cpp/nibbler/core
// 
// Made by tardif stephanie
// Login   <tardif_a@epitech.net>
// 
// Started on  Fri Apr  4 18:38:25 2014 tardif stephanie
// Last update Sun Apr  6 22:16:09 2014 ilyes abd-lillah
//

#include "SdlLib.hh"

void		SdlLib::my_puterror(std::string const& err) const
{
  std::cerr << "./nibbler: error: " << err << std::endl;
  exit(EXIT_FAILURE);
}

SdlLib::SdlLib(int height, int length)
{
  std::fstream	fs2;
  std::fstream	fs3;
  std::fstream  fs4;
  std::fstream	fs1;
  std::fstream  fs5;

  this->_height = height;
  this->_length = length;
  fs2.open("Box_Green.png");
  fs1.open("Box_Blue.png");
  fs3.open("Box_Red.png");
  fs4.open("chiptune.wav");
  fs5.open("wall.png");
  if (!(fs2.is_open()) || !(fs3.is_open()) || !(fs1.is_open()) || !(fs4.is_open()) || !(fs5.is_open()))
    this->my_puterror("Cannot load sprite");
  this->snake = IMG_Load("Box_Green.png");
  if (!this->snake)
    this->my_puterror("IMG_Load failure");
  this->bkgr = IMG_Load("wall.png");
  if (!this->bkgr)
    this->my_puterror("IMG_Load failure");
  this->wall = IMG_Load("Box_Blue.png");
  if (!this->wall)
    this->my_puterror("IMG_Load failure");
  this->food = IMG_Load("Box_Red.png");
  if (!this->food)
    this->my_puterror("IMG_Load failure");
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
    this->my_puterror("SDL Init failure"); 
  this->screen = SDL_SetVideoMode(height * 36, length * 36, 32, SDL_HWSURFACE);
  if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    this->my_puterror("Sound not found, (No DJ tonight guys !!).");
  if ((this->sound = Mix_LoadWAV("chiptune.wav")) == NULL)
    this->my_puterror("Sound not found, (No DJ tonight guys !!).");
  if (this->screen == NULL)
    this->my_puterror("SDL Video failure");
  SDL_WM_SetCaption("Nibbler v. 0.8.7", NULL);
}

SdlLib::~SdlLib()
{
  SDL_FreeSurface(this->snake);
  SDL_FreeSurface(this->bkgr);
  SDL_FreeSurface(this->wall);
  SDL_FreeSurface(this->food);
  SDL_Quit();
}

int		SdlLib::catchKey() const
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      return 0;
      break;
    case SDL_KEYDOWN:
      switch ((int)event.key.keysym.sym)
  	{
	case SDLK_ESCAPE:
	  return 0;
	  break;
  	case SDLK_LEFT:
  	  return 1;
  	  break;
  	case SDLK_RIGHT:
  	  return 2;
  	  break;
  	default:
  	  return 3;
	  break;
  	}
    default:
      return -1;
      break;
    }
}	

void		SdlLib::refresh()
{
  SDL_Rect sky;
  static int x;

  if (SDL_FillRect(this->screen, NULL, SDL_MapRGB(this->screen->format, 0, 0, 0)) == -1)
    this->my_puterror("FillRect Failure");

  x -= 1;
  if (x == 1320)
    x == 1320;
  sky.x = x;
  sky.y = -200;
  if (SDL_BlitSurface(this->bkgr, NULL, this->screen, &sky) < 0)
    this->my_puterror("BlitSurface Failure");
}

void		SdlLib::update()
{
  SDL_UpdateRect(this->screen, 0, 0, 0, 0);
}

void		SdlLib::displayWall()
{
  SDL_Rect sky;
  SDL_Rect coord;

  Mix_PlayChannel(-1, this->sound, 0);
  for (int i = 0; i <= this->_height; i++)
    {
      if (i == 0 || i == this->_height - 1)
	{
	  for (int j = 0; j <= this->_length; j++)
	    {
	      coord.x = i * 36;
	      coord.y = j * 36;
	      if (SDL_BlitSurface(this->wall, NULL, this->screen, &coord) < 0)
		this->my_puterror("BlitSurface failure");
	    }
	}
    }
  for (int i = 0; i <= this->_height; i++)
    {
      for (int j = 0; j <= this->_length; j++)
	{
	  if (j == 0 || j == this->_length - 1)
	    {
	      coord.x = i * 36;
	      coord.y = j * 36;
	      if (SDL_BlitSurface(this->wall, NULL, this->screen, &coord) < 0)
		this->my_puterror("BlitSurface failure");
	    }
	}
    }
}

void		SdlLib::putSprite(const int & x, const int & y, const int & dir, const int & flag)
{
  SDL_Rect coord;

  coord.x = x * 36;
  coord.y = y * 36;
  if (flag == 0)
    {    
      if (SDL_BlitSurface(this->snake, NULL, this->screen, &coord) < 0)
	this->my_puterror("BlitSurface failure");
    }
  else
    {
      if (SDL_BlitSurface(this->food, NULL, this->screen, &coord) < 0)
	this->my_puterror("BlitSurface failure");
    }
  this->displayWall();
}

extern "C"
{
  SdlLib *init(int height, int length)
  {
    SdlLib *sdl = new SdlLib(height, length);
    return (sdl);
  }
}

//
// OpenglLib.cpp for  in /home/abd-li_i/rendu/cpp_nibbler/sdl
// 
// Made by ilyes abd-lillah
// Login   <abd-li_i@epitech.net>
// 
// Started on  Sun Apr  6 16:00:24 2014 ilyes abd-lillah
// Last update Sun Apr  6 22:13:54 2014 ilyes abd-lillah
//

#include "OpenglLib.hh"

OpenglLib::OpenglLib(int height, int length)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    this->my_puterror("SDL Init failure"); 
  this->screen = SDL_SetVideoMode(height * 36, length * 36, 32, SDL_OPENGL);
  if (this->screen == NULL)
    this->my_puterror("SDL Video failure");
  SDL_WM_SetCaption("Nibbler v. 0.8.7", NULL);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, height * 36, length * 36, 0, 0, 1);
  glEnable(GL_DEPTH_TEST);
}

OpenglLib::~OpenglLib()
{
  SDL_Quit();
}

void		OpenglLib::my_puterror(std::string const& err) const
{
  std::cerr << "./nibbler: error: " << err << std::endl;
  exit(EXIT_FAILURE);
}

void		OpenglLib::putSprite(const int & x, const int & y, const int & dir, const int & flag)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  if (flag == 0)
    {
      glBegin(GL_QUADS);
      glColor3ub(0, 178, 178);
      glVertex2f(30 + (36 * x), 30 + (36 * y));
      glVertex2f(66 + (36 * x), 30 + (36 * y));
      glColor3ub(0, 41, 41);
      glVertex2f(66 + (36 * x), 66 + (36 * y));
      glVertex2f(30 + (36 * x), 66 + (36 * y));
      glEnd();
   }
  else
    {
      glBegin(GL_QUADS);
      glColor3ub(200, 140, 0);
      glVertex2f(30 + (36 * x), 30 + (36 * y));
      glVertex2f(66 + (36 * x), 30 + (36 * y));
      glColor3ub(200, 2, 0);
      glVertex2f(66 + (36 * x), 66 + (36 * y));
      glVertex2f(30 + (36 * x), 66 + (36 * y));
      glEnd();
    }
  glFlush();
  SDL_GL_SwapBuffers();
}

void		OpenglLib::refresh()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int		OpenglLib::catchKey() const
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

void		OpenglLib::update()
{
}

extern "C"
{
  OpenglLib *init(int height, int length)
  {
    OpenglLib *Opengl = new OpenglLib(height, length);
    return (Opengl);
  }
}

//
// Ncurseslib.cpp for  in /home/abd-li_i/rendu/cpp_nibbler/ncurses
// 
// Made by ilyes abd-lillah
// Login   <abd-li_i@epitech.net>
// 
// Started on  Sat Apr  5 14:34:50 2014 ilyes abd-lillah
// Last update Sun Apr  6 23:20:11 2014 ilyes abd-lillah
//

#include "NcursesLib.hh"

NcursesLib::NcursesLib(int height, int lenght)
{
  if (initscr() == NULL)
    this->my_puterror("Init NcursesLibrairies Fail");
  if (noecho() == ERR || cbreak() == ERR || keypad(stdscr, TRUE) == ERR)
    this->my_puterror("Init NcursesLibrairies Fail");
  if ((this->screen = newwin((height + 1), (lenght + 1), 0, 0)) == NULL)
    this->my_puterror("Failed to open a new screen (NcursesLibraires)");
  if (curs_set(0) == ERR)
    this->my_puterror("Failed to hide the cursor (NcursesLibraires)");
  keypad(this->screen, TRUE);
}

NcursesLib::~NcursesLib()
{
  if ((delwin(this->screen)) == ERR || endwin() == ERR)
    this->my_puterror("Failed to close screen (NcursesLibraires)");
  std::cout << "Hope you enjoyed the game, see you soon ! :)" << std::endl;
}

void		NcursesLib::my_puterror(std::string const& err) const
{
  std::cerr << "./nibbler: error: " << err << std::endl;
  exit(EXIT_FAILURE);
}

void		NcursesLib::putSprite(const int & x, const int & y, const int & dir, const int & flag)
{
  if (!flag)
    {
      if (mvprintw(x, y, "%c", 'x') == ERR)
	this->my_puterror("Failed to add sprite (NcursesLib)");
    }
  else
    {
      if (mvprintw(x, y, "%s", "o") == ERR)
	this->my_puterror("Failed to add sprite (NcursesLib)");
    }
}

int		NcursesLib::catchKey() const
{
  int		keyindex;
 
  if ((nodelay(this->screen, TRUE)) == ERR)
    this->my_puterror("Nodelay failure");
  timeout(220);
  if ((keyindex == getch()) == ERR)
    this->my_puterror("Keyboard event cannot found, oh my dayum !! (NcursesLibraires)");
  switch (getch())
    {
    case 27:
      return (0);
      break;
    case KEY_LEFT:
      return (1);
      break;
    case KEY_RIGHT:
      return (2);
      break;
    }
}

void		NcursesLib::refresh()
{
  if (wrefresh(this->screen) == ERR)
    this->my_puterror("Failed to refresh window. (NcursesLibraires)");
}

void		NcursesLib::update()
{
  if (wclear(this->screen) == ERR)
    this->my_puterror("Failed to update the screen. (NcursesLibraires)");
  if (box(this->screen, 0, 0) == ERR)
    this->my_puterror("Failed to draw borders of screen (NcursesLibraires)");
}

extern "C"
{
  NcursesLib *init(int height, int lenght)
  {
    NcursesLib *Ncurses = new NcursesLib(height, lenght);
    return (Ncurses);
  }
}

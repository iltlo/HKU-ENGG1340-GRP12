#include <ncurses.h>

#include "start_menu.hpp"
#include "new_game.hpp"

// main loop of the game,
// exit only when game closed
int main()
{
    initscr();
    cbreak();
    noecho();
    start_color();

    bool n_exit_game = true;

    // branching the game into serval modes (features/mode to be added)
    while(n_exit_game)
    {
        WINDOW* menu_pic_win = newwin(menu_pic_y, menu_pic_x, 0, 0);
        WINDOW* option_win = newwin(option_win_y, option_win_x, 0, menu_pic_x);

        switch(start_menu(menu_pic_win, option_win))
        {
            case(s_new_game):
            new_game();
            break;

            // case(s_option):
            //     option();
            //     break;

            case(s_exit_game):
                n_exit_game = false;
                curs_set(1);
                break;

            default:
                continue;
        }
    }
    endwin();
}
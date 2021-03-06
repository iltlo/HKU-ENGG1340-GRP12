#include <ncurses.h>

#include "start_menu.hpp"
#include "new_game.hpp"
#include "save_and_load.hpp"

// main loop of the game,
// exit only when game closed
int main()
{
    initscr();
    cbreak();
    noecho();
    start_color();

    bool n_exit_game = true, load;

    // branching the game into serval modes (features/mode to be added)
    while(n_exit_game)
    {
        WINDOW* menu_pic_win = newwin(menu_pic_y, menu_pic_x, 0, 0);
        WINDOW* option_win = newwin(option_win_y, option_win_x, 0, menu_pic_x);
        WINDOW* leaderboard_win = newwin(leaderboard_win_y, leaderboard_win_x, (term_y-leaderboard_win_y)/2, (term_x-leaderboard_win_x)/2);

        switch(start_menu(menu_pic_win, option_win))
        {
            case(s_new_game):
                load = false;
                closing_start_menu(menu_pic_win, option_win);
                start_game(load);
                break;

            case(s_load):
                load = true;
                closing_start_menu(menu_pic_win, option_win);
                start_game(load);
                break;

            case (s_leaderboard):
                n_exit_game = true;
                show_leaderboard(leaderboard_win);
                break;

            case(s_exit_game):
                closing_start_menu(menu_pic_win, option_win);
                n_exit_game = false;
                curs_set(1);
                break;

            default:
                continue;
        }
    }
    endwin();
}
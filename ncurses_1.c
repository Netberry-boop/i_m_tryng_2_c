
/* ncurses_1.c */
#include <ncurses.h>

int main()
{
    int x, y;
    initscr();
    clear();

    getyx(stdscr, y, x); // it locates the current positon of cursor on the screen and gets their coordinates

    printw("x = %d\n , y = %d\n ", x, y); // prints cursor coordiantes
    refresh();

    y = 5;  // 5 lines down
    x = 10; // 10 characters to the right

    move(y, x);

    printw("Over here!!");
    refresh();

    getch(); // holding the scree untill a key is pressed
    endwin();

    return 0;
}
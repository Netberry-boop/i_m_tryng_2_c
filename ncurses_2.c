/* ncurses.c */

#include <ncurses.h>

int main()
{
    int key; // key_left and key_right are integer constants often larger than char can hold
    int x, y;
    initscr();
    keypad(stdscr, TRUE); // for allowing the keypad arrows
    noecho();             // this disables the default echo settings of terminal
    printw("press left or right arrow - exit by pressing by pressing : q");
    refresh(); // this prints, reloads the windw with latest print statements
    while (key != 'q')
    {                  // char check to end the loop
        key = getch(); // all the keys including the arrows
        if (key == KEY_LEFT)
        { // left arr input
            x--;
            if (x < 0)
            {
                x = 0;
            }
        }
        if (key == KEY_RIGHT)
        { // right arr input
            x++;
            if (x > 30)
            {
                x = 30;
            }
        }
        clear();
        move(y, x); // updates position of cursor
        printw("o");
        refresh(); // prints and reloads the window
    }
    endwin(); // destroys the window
    return 0;
}

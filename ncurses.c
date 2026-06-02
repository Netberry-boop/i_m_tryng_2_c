#include <ncurses.h>

int main()

{

    char letter;

    // ncurses manages text-based windows on the terminal screen

    initscr(); // initialize ncurses and creates default window

    printw("Press any key : "); // prints text to the current ncurses window

    refresh(); // update the terminal with changes made to the window

    letter = getch(); //ncurses way of taking input(keys, letters, numbers)

    clear(); // clear the current window and marks it for redraw

    printw("you pushed: '%c'\n", letter);

    refresh(); // update the terminal with the changes made to the window

    getch(); // wait for a key press so that the output remains
    
    endwin(); // destroying the ncurses window 

   return 0; 

}

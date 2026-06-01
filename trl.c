/* trl.c time to read line */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>  // to make the time out part
#include <sys/types.h> // for "select()" function
#include <unistd.h>
#include <string.h> // to manipulate string

char *trl(int timeout)
{
  static char buf[512];

  /* here static is used so that the data inside the buffer remains intact throughout
   program execution */

  /* standard file descriptors provided by the operating system when a process starts
   FD 0 - (stdin) usually your keyboard
   FD 1 - (stdout) terminal screen
   FD 2 - (stderr) also screen, used for error messages
 */

  fd_set rfds;       // declaring a fd_set type variable rfds, it is similar to watchlist
  struct timeval tv; // structure for storing time
  int ret;           // the return value
  FD_ZERO(&rfds);    // clearing the list - zeroing the watch list
  FD_SET(0, &rfds);  // adding "0" to the rfds watch list, meaning watch out for keyboard input

  tv.tv_sec = timeout;
  // storing the time part for timeout in specific time structure - tv_sec & tv_usec
  tv.tv_usec = 0;

  ret = select(1, &rfds, 0, 0, &tv); // syntax (nfds, keyboard stream, not set(read), not set(error), timeout)
  // nfds - "1" in select is used to set an upper limit, to tell select() to go through this range of fds
  // nfds = highest file descriptor + 1, because file descriptor starts from 0
  if (ret && FD_ISSET(0, &rfds)) // if keyboard-input and if file descriptor is set to keyboard input
  {
    memset(buf, 0, 512);     // this clear the buffer - for 512 byte, this is to prevent display of old bytes with the new input
    ret = read(0, buf, 511); // this returns the number of bytes read from the input
    if (ret < 1)             // EOF or reading error
      return NULL;           // if read bytes less than 1
    ret--;                   // removing the last character that is "\n" - caused dues to enter key
    buf[ret] = '\0';         // last character set to null to mark ending
    return buf;              // returning the string
  }
  return NULL; // if nothing is read
}

int main()
{
  char *name;
  printf("what is your name? think fast!\n");
  name = trl(3); // timeout set to 3 seconds
  if (name)
    printf("Hello %s\n", name);
  else
    printf("Too slow!\n");
  return 0;
}
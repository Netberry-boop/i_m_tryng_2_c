/* xor.c */

// this program demonstrates character encryption using XOR operation

#include <stdio.h>
#include <math.h>
#define KEY 'X';
#define CLEARTEXT 'A';

void printchar(char *text, char letter)
{
  printf("%s => '%c' - (%x)\n", text, letter, letter); // %x is hexcode of letter passed as argument
  return;
}

int main()
{
  char cleartext, key, ciphertext, newcleartext;
  cleartext = CLEARTEXT;
  printchar("plain text", cleartext);

  key = KEY;
  printchar("key", key);

  ciphertext = cleartext ^ key; // this is xor operation
  printchar("cipher text", ciphertext);

  newcleartext = ciphertext ^ key;
  printchar("new plain text", newcleartext);

  return 0;
}

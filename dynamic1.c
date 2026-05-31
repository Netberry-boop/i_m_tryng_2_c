/* dynamic1.c */

#include<stdio.h>
#include<stdlib.h> //contains the "malloc()" function 

int main()

{
 char *name;
 name = malloc(32); // dynamic allocation of 32 bytes of memory 
 printf("what is your name ?\n");
 scanf("%s",name); //here the name of the string "name" - decays into pointer to the first character - "&name[0]", therefore no need of "&"  
 printf("Hello %s\n",name);
 
 free(name); // good habit to always free the memory allocation
 return 0;

}



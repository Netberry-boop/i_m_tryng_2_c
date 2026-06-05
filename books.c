/* books.c */
/* a linked list is long chain of structure, way to accomplish this in c is by creating a structure and within
 the structure having a pointer of same structure type */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct library{ // linked list structure 
    char title[64]; // 2 components in the data section - "title" and "pages" 
    int pages;
    struct library *next; // the address/ link section can store pointer/address of library datatype
};

typedef struct library book; // variable of library datatype (a node in this case)

book *first; // first node 
int num_books;

void add_book(char* title, int n_pages){
    book *p, *new;
    if(!first){
        p = malloc(sizeof(book));
        memset(p,0,sizeof(book));
        num_books++;
        strncpy(p->title,title,63);
        p->pages = n_pages;
        p->next = 0 ;
        first = p;    
        return;
    }
    for (p=first;p->next;p = p->next);
        new = malloc(sizeof(book));
        memset(new,0,sizeof(book));
        num_books++;
        strncpy(new->title,title,63);
        new->pages = n_pages;
        new->next = 0 ;
        p->next = new;
        return;
    
}

int main(){
 first = 0 ;
 num_books = 0 ; 
 add_book("the bible", 3500);
 printf("%s\n",first->title);
 return 0;
}

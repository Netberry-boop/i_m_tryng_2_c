
/* struct.c */

#include<stdio.h>

typedef struct coordinate { // typedef is used here to define a type name/shorthand for the struct
    char *subject;
    int x; // it is recommended that we arrange fields from highest size to lowest size to cause minimum padding 
    int y;// padding is a way to align the sizes of the components that are contiguous for faster retrieval 
    int z;// int here is 4 bytes as the system is 64-bit , and the char array is standard 8 bytes 
     
}coord_t; // this is the type name given to the struct, this name can now be used to declare the coordinate estruct type variable. 
// the _t usage is encourage as it indicates a custom datatype .

int main(){
    coord_t my_c = { // this way of assigning value is called designated initializers 
        .x = 0,
        .y = 0,
        .z = 0,
        .subject = "coordinate geometry", // designated cause the order of assignment doesn't matter as we are tageting via field name.
    };
    printf("the initial coordinates in subject %s is taken as %d,%d,%d\n",my_c.subject,my_c.x,my_c.y,my_c.z);
    return 0 ; 
}


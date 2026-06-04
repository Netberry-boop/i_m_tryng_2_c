/*fp.c*/
// its a variable that points to another function (and use this variable to work with function)
#include<stdio.h>

void add(int *target, int a, int b){
	*target = a+b; // if * not neighbour to then the * represents the action of dereferencing 
	return ;
}
void subtract(int *target, int a, int b){
        *target = a-b; // if * not neighbour to then the * represents the action of dereferencing 
        return ;
}
void multiply(int *target, int a, int b){
        *target = a*b; // if * not neighbour to then the * represents the action of dereferencing 
        return ;
}
void divide(int *target, int a, int b){
        *target = a/b; // if * not neighbour to then the * represents the action of dereferencing 
        return ;
}

int main(){
	int a , b , c;
	char op; 
	printf("what operation do you want to perform ?(+,-,*,/) : ");
	scanf("%c",&op);
	switch(op){
	case '+' :
		printf("enter numbers you want to add : ");
		scanf("%d%d",&a,&b);
		add(&c,a,b);
		printf("the sum is %d\n",c);
		break;
	 case '-' :
                printf("enter numbers you want to subtract : ");
                scanf("%d%d",&a,&b);
                subtract(&c,a,b);
                printf("the difference is %d\n",c);
                break;
	 case '*' :
                printf("enter numbers you want to multiply : ");
                scanf("%d%d",&a,&b);
                multiply(&c,a,b);
                printf("the product is %d\n",c);
                break;
	 case '/' :
                printf("enter numbers you want to divide : ");
                scanf("%d%d",&a,&b);
                divide(&c,a,b);
                printf("the quotient is %d\n",c);
                break;
	default : 
		printf("Error , improper op_code\n");

	}
	return 0 ; 
}

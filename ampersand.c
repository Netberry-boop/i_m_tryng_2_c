/* ampersand.c */
#include<stdio.h>

void addition(int a , int b, int *result){
	*result = a+b; 
// direct manipulation - result here is not a copy, it is the real "answer" variable - from the main funtion being altered
}

int main(){
	int x,y, answer;
	x = 5; // here the values are hardcoded into the variable    
	y = 15;
	addition(x,y,&answer); // the literal meaning of "&" is address of operator, address is being passed as argument 
	// the passing of address rather than value is what allows direct memory manipulation of the variable - "answer"
	printf("%d\n", answer);
	return 0;
}

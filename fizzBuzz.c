/**
 The famous fizzBuzz program which takes a number
 and determines whether 3 and/or 5 are factors and
 prints fizz (for 3) , buzz (for 5), or fizz buzz
 (for both 3 and 5)
**/
#include <stdlib.h>
#include <stdio.h>

void fizzBuzz(int num){

	//if 5 and 3 are factors of num
	if( (num%5==0) && ( num %3 ==0)){
		printf("fizz buzz\n");
	}
	//if 3 is a factor of num
	else if(num %3 ==0){
		printf("fizz\n");
	}
	//if 5 is a factor of num
	else if(num % 5 == 0){
		printf("buzz\n");
	}
	//else just print num
	else {
		printf("%d\n",num);
	}
}

int main(void){

	// increment variable
	int i;

	for(i=1;i<=15;i++){
		fizzBuzz(i);
	}
}

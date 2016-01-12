/***
  Binary Search program which halves input data in search for some value
  Assumptions(if any): data being searched is in ascending/descending
    order depending on implementation
  Running Time: O(lg(n))
***/

#include <stdio.h>
#include <stdlib.h>
int main(void){

  // indices of left most, right most,and middle elements
  int left=0, right, middle;

  // value being searched for in array
  int searchFor;

  // array of data to be searched
  // data[]: statically declared & in ascending order
  // works with dynamically allocated array as well
  int data[10] ={3,4,9,11,15,18,22,27,29,32};

  // right index dependent on number of elements in list
  // -1 to compensate for starting array index of 0
  // right = number of bytes in array / bytes in an int
  right= (sizeof(data)/sizeof(int)) - 1;

  // read user keystrokes from stdin (standard input) buffer
  printf("Search For The Number:\n");

  // scanf not recommended for critical code
  // no error checking done for non-integer or 0 as input value
  scanf("%d",&searchFor);

  // works for even and odd number of elements in array
  while(left<=right){

    // halving (size of array) at every iteration
    middle=(left+right)/2;

    // is number in the middle of array?
    if (searchFor == data[middle]){
      printf("Number Found At Index: %d\n",middle);
      //program (main function) terminates if number is found
      exit(1);
    }
    // search in lower halve of array
    else if(searchFor<data[middle]){
       right=middle-1;
    }
    // search in upper halve of array
    else{
       left =middle+1;
    }
  }
  //statement only reached if number is never found in while loop above
  printf("Number Never Found\n");
  }

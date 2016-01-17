#include <stdio.h>
#include <stdlib.h>

// List is simply a pointer to the first some of some List
typedef struct struct_list * List;
// Link is another name for node in List
typedef struct node * Link;

struct struct_list{
	Link first;
};

struct node{
	int item;
	Link next;
};

List newList();
void destroyList(List myList);
void printList(List myList);
void insertLink(List myList,Link prev,Link linkToAdd);
void deleteNext(List myList,Link prev);
List insertionSort(List myList);
Link newLink(int value);
/**
 * Allocates memory for some node (Link) and returns that node
 **/
Link newLink(int value){
	Link new = malloc(sizeof(*new));
	new->item=value;
	new->next=NULL;
	return new;
}
/**
 * Returns a new sorted list from some original list which is not changed
 * Sorting is in ascending order based on the value attribute contained in each node (Link)
**/
List insertionSort(List myList){
	Link i;
	List sortedList = newList();
	for(i=myList->first;i != NULL; i=i->next){

		Link current =NULL; //at first the node were working with in the sortedList is NULL after every iteration
		int value = i->item; //value of the node were currently looking to place
		Link next =sortedList->first; //the next node were working with is the start of the sorted list
		while((next !=NULL) &&(value>next->item)){ //we begin traversing from the start of the sorted list to determine where to place a node
			current= next; //current node were working with
			next=next->next; //continue iterating
		}
		insertLink(sortedList,current,newLink(value)); //we create a new link with a copy of the value of the node we were looking to place instead of using the original
	}
	return sortedList;
}
/**
 * Deletes the node (Link) following some specified previous node
**/
void deleteNext(List myList, Link prev){
	Link temp = prev->next;
	prev->next=temp->next;
	free(temp);
}
/**
* Inserts a node(Link) into some list after some given previous link 
**/
void insertLink(List myList,Link prev,Link linkToAdd){
	if(prev == NULL){
		linkToAdd->next=myList->first; //  make pointer of added node point to start of list
		myList->first=linkToAdd;	//make the added node now be the first node of the list
	}
	else{
		linkToAdd->next = prev->next;
		prev->next = linkToAdd;
	}
}
/**
 * allocated memory for List structure which simply contains pointer to starting node of list
 **/
List newList(){
	List myList = malloc(sizeof(*myList));
	myList->first= NULL; //set list first node to null b/c its empty
	return myList;
}
/**
 * Frees the memory allocated for every node in the linked list that is passed
 **/
void destroyList(List myList){
	Link i = myList->first;
	Link temp;
	if (i!=NULL){
		while(i!=NULL){
			temp = i->next;
			free(i);
			i=temp;
		}
	}
	free(myList);
}
/**
 * Traverses a List and prints the value contained in every node within the List
 **/
void printList(List myList){
	Link temp= myList->first;
	while(temp!=NULL){
		printf("%d\n",temp->item);
		temp=temp->next;
	}
}

int main(void)
{
	// aList is standard list in which nodes (Links) are added in sequential fashion
	List aList = newList();
	
	// myList used to demonstrate insertion sort on some List whose nodes (Links)
	// contain pseudo-random gererated numbers
	List myList = newList();

	int counter=0;
	Link node=NULL;
	Link prev=NULL;
	// User input taken  (no error checking for preverse input done)
	// User inputs a  number corresponding to the size of a linked list he/she wants
	int n;
	printf("Size of List, please?:\n");
	scanf("%d",&n);

	// 
	for(counter=1;counter<=n;counter++){
		node = malloc(sizeof(*node));
		node->item=counter;
		// node->next=aList->first;
		// aList->first=node;

		// insert a node (Link) containing the value of counter at some iteration
		// using the prev node (Link) to determine placement within the list 
		// in this case insertLink inserts each node (Link) in sequential order 
		insertLink(aList,prev,node);
		prev=node;

	}

	// generates random number and inserts it to node (Link)
	// which is then added to a List (myList)
	for(counter=0;counter<n;counter++){
		int num=rand()%1000;
		insertLink(myList,NULL,newLink(num));
	}
	
	printf("unsorted list:\n");
	printList(myList);

	// sort myList
	myList = insertionSort(myList);

	printf("sorted list:\n");
	printList(myList);
	
	// freeing memory of both list
  	destroyList(myList);
	destroyList(aList);
}

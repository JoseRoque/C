#include <stdio.h>
#include <stdlib.h>

typedef struct struct_list * List;
typedef struct node * Link;
struct struct_list{
	Link first;
};

struct node{
	int item;
	Link next;
};

List newList();
List reverseList();
void destroyList(List myList);
void printList(List myList);
void insertLink(List myList,Link prev,Link linkToAdd);
void deleteNextLink(List myList,Link prev);
List insertionSort(List myList);
Link newLink(int value);

Link newLink(int value){
	Link new = malloc(sizeof(*new));
	new->item=value;
	new->next=NULL;
	return new;
}
//returns a new list which is sorted and doesnt change the original one
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
void deleteNextLink(List myList, Link prev){
	Link temp = prev->next;
	prev->next=temp->next;
	free(temp);
}
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
List newList(){
	List myList = malloc(sizeof(*myList));
	myList->first= NULL; //set list first node to null b/c its empty
	return myList;
}

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

void printList(List myList){
	Link temp= myList->first;
	while(temp!=NULL){
		printf("%d\n",temp->item);
		temp=temp->next;
	}
}

List reverseList(List myList){
	//i have to free the list provided as argument if i want to replace it
	//in this case nodes are appended to the head they become the head after added

	Link current = myList->first; // currently viewing first node to be processed
	List processed = newList(); //intially no nodes have been processed thus processed list is empty
	Link temp;

	while(current!=NULL){
		temp = current->next;// save the next link following the first node in the first iteration
		current->next=processed->first; //at first iteration the processed list is empty make pointer point to starting node (NULL if its the first iteration)
		processed->first=current; // the processed first is now considered that node we just addded
		current=temp;
	}
	return processed;
}

int main(void)
{

	List aList = newList();
	int counter;
	Link node;
	Link prev=NULL;

	int n;
	printf("Enter a number please:\n");
  // *no error checking on input done
	scanf("%d",&n);

	for(counter=1;counter<=n;counter++){
		node = malloc(sizeof(*node));
		node->item=counter;
//		node->next=aList->first;
//		aList->first=node;

		insertLink(aList,prev,node);
		prev=node;

	}

	printf("printing list in order:\n");
	printList(aList);

	aList = reverseList(aList);

	printf("printing list in reverse order:\n");
	printList(aList);

}

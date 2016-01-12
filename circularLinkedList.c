#include <stdio.h>
#include <stdlib.h>

typedef struct node * Link;
typedef struct struct_list * List;

 struct node{
  int item;
  Link prev;
  Link next;
};

struct struct_list{
  Link head;
  Link current;
};

List newList(){
  List newList = malloc(sizeof(*newList));
  newList->head =NULL;
  newList->current =NULL;
  return newList;
}

Link newLink(int value){
  Link newLink= malloc(sizeof(*newLink));
  newLink->item =value;
  newLink->next=NULL;
  newLink->prev=NULL;
  return newLink;
}
void insertLink(List list, Link link){
  Link current = list->head;

  if(current == NULL){
    list->head = link;
    link->prev =link; //if list is empty only node points to itself
    link->next =link;
  }
  else{

    Link temp = current->prev;
    current->prev=link;
    link->next=temp->next;
    link->prev=temp;
    temp->next=link;
    list->head=link;
  }
  return;
}
//
void insertLink2(List list, Link link, int index){
  Link h =  list->head;
  Link temp;
}

void printList(List list){
  Link temp = list->head;
  Link end = list->head;

  if(temp==NULL){
    printf("list is empty\n");
    return;
  }
  else{
    do{
      printf("%d\n",temp->item);
      temp=temp->prev;
    }while(temp!=end);
  }
}
int main(void){

  int data[10] = {1,2,3,4,5,6,7,8,9,0};
  Link myLink;
  List myList = newList();
  int i=0;
  int value=0; //value to be added to list
  int sizeOfList =(sizeof(data)/sizeof(int));


  for(i=0;i<sizeOfList;i++){
     myLink = newLink(data[i]);
     insertLink(myList, myLink);
  }
  printList(myList);

}

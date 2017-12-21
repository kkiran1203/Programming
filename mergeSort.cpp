#include <stdio.h>
#include <iostream>

using namespace std;
/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Structure of the linked list node is as */
struct node
{
  int data;
  struct node* next;
};

void mergeSort(struct node **headRef );
void printList( struct node *node );
/* split the nodes of the given list into front and back halves,
     and return the two lists using the reference parameters.*/
void splitList(struct node* source, struct node** frontRef, struct node** backRef)
{
  *frontRef = source;
  if( source==NULL ) {
    return;
  }
  if( source->next == NULL ) {
    *frontRef = source;
  }
  struct node* temp = source;
  int length = 1;
  while( temp->next !=NULL ) {
    length++;
    temp = temp->next;
  }
  //cout << "kiran\n";
  int size = length;
  if( length%2 == 1 ) {
    size = length + 1;
  }
  for( int i=0; i<size/2-1; i++ ) {
    source = source->next;
  }
  *backRef = source->next;
  source->next = NULL;
  printList( *frontRef );
  printList( *backRef );
  // Code here
}
// merges two sorted list into one big list
struct node* mergeList(struct node* a, struct node* b)
{
  struct node* finalList=NULL;
  struct node *prev = finalList;
  cout << " show lists to merge\n";
  printList( a );
  printList( b );
  while( a!=NULL && b!=NULL ) {
    struct node *temp = (struct node*)malloc( sizeof( struct node) );
    //cout << "kiran\n";
    if( a->data < b->data ) {
      temp->data = a->data;
      temp->next=NULL;
      //printList( a );
      //printList( b );
      if( prev == NULL ) {
	finalList = temp;
	prev = finalList;
      } else {
	prev->next = temp;
	prev = prev->next;
      }
      a = a->next;
    } else {
      temp->data = b->data;
      temp->next=NULL;
      if( prev == NULL ) {
        finalList = temp;
        prev = finalList;
      } else {
        prev->next = temp;
        prev = prev->next;
      }
      b = b->next;
    }
  }
  cout << " printing before appending\n";
  printList( a );
  printList( b );
  if( a !=NULL ) {
    prev->next = a;
  }
  if( b !=NULL ) {
    prev->next = b;
  }
  cout << " after merge    ";
  printList( finalList );
  return finalList;
  // Code here
}

void mergeSort(struct node **headRef)
{
  struct node* head = *headRef;
  struct node* a=NULL;
  struct node* b=NULL;
  if ((head == NULL) || (head->next == NULL))
    return;
  splitList(head, &a, &b); 
  mergeSort(&a);
  mergeSort(&b);
  *headRef = mergeList(a, b);
}

void push( struct node** headRef, int data ) {
  struct node* newnode = (struct node*)malloc( sizeof( struct node) );
  newnode->data = data;
  newnode->next=*headRef;
  *headRef=newnode;
  
}

void printList( struct node *node ) {
  while( node!=NULL ) {
    cout << node->data << " -> ";
    node = node->next;
  }
  cout << "\n";
}

int main() {
  struct node* head=NULL;
  push( &head, 5 );
  push( &head, 10 );
  push( &head, 4 );
  push( &head, 7 );
  push( &head, 11 );
  push( &head, 1 );
  printList( head );
  mergeSort( &head );
  printList( head );
  
}

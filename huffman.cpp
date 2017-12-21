#include<stdio.h>
#include<iostream>

using namespace std;

struct node {
  char ch;
  int freq;
  struct node *left, *right;
};

struct minheap {
  int size;
  struct node **arr;
};

void swap( struct minheap* heap, int x, int y ) {
  struct node* temp = new node;
  temp->ch = heap->arr[x]->ch;
  temp->freq = heap->arr[x]->freq;
  temp->left = heap->arr[x]->left;
  temp->right = heap->arr[x]->right;
  heap->arr[x]->ch = heap->arr[y]->ch;
  heap->arr[x]->freq = heap->arr[y]->freq;
  heap->arr[x]->left = heap->arr[y]->left;
  heap->arr[x]->right = heap->arr[y]->right;
  heap->arr[y]->ch = temp->ch;
  heap->arr[y]->freq = temp->freq;
  heap->arr[y]->left = temp->left;
  heap->arr[y]->right = temp->right;
}

void minHeapify( struct minheap* heap, int i ) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int small = i;
  if( left < heap->size && heap->arr[ i ]->freq > heap->arr[left]->freq ) {
    small = left;
  }
  if( right < heap->size && heap->arr[ small ]->freq > heap->arr[right]->freq ) {
    small = right;
  }
  if( small != i ) {
    swap( heap, small, i );
    minHeapify( heap, small );
  }

}

void buildMinheap( struct minheap* heap ) {
  for( int i=(heap->size - 1 )/2; i >=0; i-- ) {
    minHeapify( heap, i );
  }
}

struct node* extractMin( struct minheap* heap ) {
  struct node* min = heap->arr[ 0 ];
  heap->arr[ 0 ] = heap->arr[ heap->size - 1 ];
  heap->size--;
  minHeapify( heap, 0 );
  return min;
}

void insertNode( struct minheap* heap, struct node* node ) {
  heap->size++;
  int i = heap->size - 1;
  while( i && node->freq < heap->arr[ (i-1)/2 ]->freq ) {
    heap->arr[ i ] = heap->arr[ (i-1)/2 ];
    i = ( i-1 )/2;
  }
  heap->arr[ i ] = node;
}

void printTree( struct node* root ) {
  if( root == NULL ) {
    return;
  }
  cout << root->freq << "->";
  if( root->left ) {
    cout << "left:";
    cout << root->left->freq << "->";
  }
  if( root->right ) {
    cout << "right:";
      cout << root->right->freq << "-> \n";
  }
  printTree( root->left );
  printTree( root->right );
}

void buildHuffmanCodes( char characters[], int freq[], int size ) {
  struct minheap* heap = new minheap;
  heap->size=size;
  heap->arr = (struct node**)malloc(size*sizeof(struct node*));
  cout << " here :" << size << "\n"; 
  for( int i=0; i<size; i++ ) {
    cout << "here1\n";
    struct node* temp = (struct node*)malloc( sizeof( struct node ) );
    cout << " here2\n"; 
    temp->ch = characters[i];
    temp->freq = freq[i];
    temp->left = NULL;
    temp->right = NULL;
    cout << " here3\n";
    heap->arr[ i ] = temp;
    cout << " here4\n";
  }
  cout << " kiran \n ";
  buildMinheap( heap );
  while( heap->size > 1 ) {
    struct node* left = extractMin( heap );
    struct node* right = extractMin( heap );
    struct node* new_node = new node;
    new_node->ch = '#';
    new_node->freq = left->freq + right->freq;
    new_node->left = left;
    new_node->right = right;
    insertNode( heap, new_node );
  }
  struct node* root = extractMin( heap );
  printTree( root );
}

int main() {
  char characters[6] = { 'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[6] = { 4, 9, 13, 14, 20, 45 };
  cout << characters<< "\n";
  buildHuffmanCodes( characters, freq, sizeof(freq)/sizeof(freq[0]) );

  return 0;
}

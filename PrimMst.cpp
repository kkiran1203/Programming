#include<stdio.h>
#include<iostream>

using namespace std;

struct Edge {
  int src, dest, weight;
};

struct Graph {
  int V;
  int E;
  struct Edge* edges;
};

int getMin( int mstVertesSet[], int key[], int size ) {
  int small;
  cout << "getMin\n ";
  for( int i=0; i<size; i++ ) {
    if( mstVertesSet[i] == -1 ) {
      small = i;
      break;
    }
  }
  cout << "getMin-here1: " << small << "\n";
  for( int i=0; i<size; i++ ) {
    if( key[i] < key[small] && mstVertesSet[ i ]==-1 ) {
      cout << " key[i] " << key[i] << "\n";
      small = i;
    } 
  }
  return small;
}

void setAdjacencies( int vertex, struct Graph* graph, int *key, int *mstVertexSet ) {
  int E = graph->E;
  cout << "kiran5\n";
  for( int i=0; i<E; i++ ) {
    if( graph->edges[i].src == vertex && mstVertexSet[ graph->edges[i].dest ] == -1 ) {
      
      if( key[ graph->edges[i].dest ] > graph->edges[i].weight ) {
	key[ graph->edges[i].dest ] = graph->edges[i].weight;
      }
    }
    if( graph->edges[i].dest == vertex && mstVertexSet[ graph->edges[i].src ] == -1 ) {
      if( key[ graph->edges[i].src ] > graph->edges[i].weight ) {
	key[ graph->edges[i].src ] = graph->edges[i].weight;
      }
    }
  }
}

void primMst( struct Graph *graph ) {
  int V = graph->V;
  cout << "kiran3\n";
  int *key = ( int* )malloc( V * sizeof( int ) );
  for( int i=0; i<V; i++ ) {
    key[i] = 100;
  }
  for( int i=0; i<V; i++ ) {
    cout <<" " << key[i] << " ";
  }
  key[ 0 ] = 0;
  struct Graph *mst = new Graph;
  mst->V = V;
  mst->E=0;
  int *mstVertexSet = ( int *)malloc( V * sizeof(int) );
  for( int i=0; i<V; i++ ) {
    mstVertexSet[i] = -1;
  }
  //memset( mstVertexSet, -1, V );
  mst->edges = (struct Edge*)malloc( (V-1) * sizeof( struct Edge ) );
  cout << "kiran4\n";
  while( mst->E < V-1 ) {
    int vertex = getMin( mstVertexSet, key, V );
    mstVertexSet[ vertex ] = 1;
    cout << "here: " << mst->E << "\n";
    setAdjacencies( vertex, graph, key, mstVertexSet );
    mst->E++;
  }
  for( int i=0; i<V; i++ ) {
    cout << key[ i ] << "  "; 
  }
  cout << "\n";
}

int main() {
  struct Graph *graph = new Graph;
  graph->V=3;
  graph->E=3;
  cout << "kiran1\n";
  graph->edges = (struct Edge*)malloc( graph->E * sizeof( struct Edge ) );
  graph->edges[0].src=0;
  graph->edges[0].dest=1;
  graph->edges[0].weight=2;
  graph->edges[1].src=1;
  graph->edges[1].dest=2;
  graph->edges[1].weight=8;
  graph->edges[2].src=0;
  graph->edges[2].dest=2;
  graph->edges[2].weight=6;
  cout << "kiran2\n";
  primMst( graph );

  return 0;
}

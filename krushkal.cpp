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

struct subset {
  int parent;
  int rank;
};

int comp( const void *a, const void *b ) {
  struct Edge *a1 = (struct Edge*)a;
  struct Edge *b1 = (struct Edge*)b;
  return a1->weight > b1->weight;
}

void printGraph( struct Graph* graph ) {
  for( int i=0; i< graph->E; i++ ) {
    cout << graph->edges[i].src << "->" << graph->edges[i].dest << " weight:" << graph->edges[i].weight << " \n ";
  }
}

int find( struct subset* subsets, int x ) {
  if( subsets[x].parent != x ) {
    subsets[x].parent = find( subsets, subsets[x].parent );
  }
  return subsets[x].parent;
}

void Union( struct subset* subsets, int x, int y ) {
  if( subsets[x].rank > subsets[y].rank ) {
    subsets[y].parent = x;
  } else if( subsets[x].rank < subsets[y].rank ) {
    subsets[x].parent =y;
  } else {
    subsets[x].parent =y;
    subsets[x].rank++;
  }
}

void krushkalMst( struct Graph* graph ) {
  int V = graph->V;
  struct subset* subsets = ( struct subset*)malloc( V * sizeof( struct subset ) );
  for( int i=0; i<V; i++ ) {
    subsets[i].parent = i;
    subsets[i].rank = 0;
  }
  int e = 0;
  int j = 0;
  struct Edge* result = ( struct Edge*)malloc( V * sizeof( struct Edge ) );
  while( e<V-1) {
    int x = find( subsets, graph->edges[j].src );
    int y = find( subsets, graph->edges[j].dest );

    if( x!=y ) {
      result[ e ].src = graph->edges[j].src;
      result[ e ].dest = graph->edges[j].dest;
      e++;
      Union( subsets, x, y );
    }
    j++;
  }
  for( int i =0; i<e; i++ ) {
    cout << result[i].src << " -> " << result[i].dest << " \n "; 
  }
}

int main() {
  struct Graph* graph;
  graph = new Graph;
  graph->V = 3;
  graph->E = 3;
  graph->edges = ( struct Edge* )malloc( (graph->E)*sizeof( struct Edge ) );
  graph->edges[0].src = 0;
  graph->edges[0].dest = 1;
  graph->edges[0].weight =  3;
  graph->edges[1].src = 1;
  graph->edges[1].dest = 2;
  graph->edges[1].weight=  2;
  graph->edges[2].src= 2;
  graph->edges[2].dest = 0;
  graph->edges[2].weight=  1;
  printGraph( graph );
  qsort( graph->edges, graph->E, sizeof( graph->edges[0] ), comp );
  printGraph( graph );

  krushkalMst( graph );
  //printGraph( mst );

  return 0;
}

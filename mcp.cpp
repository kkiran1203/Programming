#include<stdio.h>
#include<cstring>
#include<iostream>

using namespace std;


int mcp( int m, int n, int cost[][ 3 ] ) {
  if( m<0 || n<0 ){
    return INT_MAX;
  }
  if( m==0 && n==0 ) {
    return cost[ m ][ n ];
  } else {
    return cost[ m ][ n ] + min( mcp( m-1, n-1, cost ), min( mcp( m-1, n, cost ),
							     mcp( m, n-1, cost ) ) );
  }

}

int main() {
  int cost[3][3] = { {1, 2, 3},
		     {4, 8, 2},
		     {1, 5, 3} };
  cout << "Minimum cost path to (2,2) is " << mcp( 2, 2, cost ) << "\n";
  
  return 0;
}

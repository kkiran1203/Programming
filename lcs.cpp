#include<stdio.h>
#include<cstring>
#include<iostream>

using namespace std;

int lcs_mem( string s1, string s2, int n1, int n2, int **mem ) {
  if( mem[ n1 ][ n2 ] != -1 ) {
    return mem[ n1 ][ n2 ];
  }
  if( n1 == 0 || n2 == 0 ) {
    if( s1[ n1 ] == s2[ n2 ] ) {
      mem[ n1 ][ n2 ] = 1;
    } else {
      mem[ n1 ][ n2 ] = 0;
    }
    return mem[ n1 ][ n2 ];
  }
  for( int i=n1; i>=1; i-- ) {
    for( int j=n2; j>=1; j-- ) {
      if( s1[ i ] == s2[ j ] ) {
	mem[ i ][ j ] = 1 + lcs_mem( s1, s2, i-1, j-1, mem );
      } else {
	mem[ i ][ j ] = max( lcs_mem( s1, s2, i, j-1, mem ),
			     lcs_mem( s1, s2, i-1, j, mem ) );
      }
    }
  }
  return mem[ n1 ][ n2 ];
}

int lcs( string s1, string s2 ) {
  int n1 = s1.length();
  int n2 = s2.length();
  int **mem;
  mem = new int *[n1];
  for( int i=0; i<n1; i++ ) {
    mem[ i ] = new int [n2];
    memset( mem[i], -1, sizeof( int ) * n2 );
  }
  int match = n1;
  for( int i=0; i<n1; i++ ) {
    if( s1[ i ] == s2[ 0 ] ) {
      mem[ i ][ 0 ] = 1;
      match = i;
      break;
    } else {
      mem[ i ][ 0 ] = 0;
    }
  }
  for( int j=match+1; j< n1; j++ ) {
    mem[ j ][ 0 ] = 1;
  }
  match = n2;
  for( int i=0; i<n2; i++ ) {
    if( s1[ 0 ] == s2[ i ] ) {
      mem[ 0 ][ i ] = 1;
      match = i;
      break;
    } else {
      mem[ 0 ][ i ] = 0;
    }
  }
  for( int j=match+1; j<n2; j++ ) {
    mem[ 0 ][ j ] = 1;
  }
  //memset( mem, -1, sizeof( int ) * n1 * n2 );
  /*for( int i=0; i< n1; i++ ) {
    for( int j=0; j<n2; j++ ) {
      cout << mem[i][j] << " ";
    }
    cout << "\n";
    }*/

  lcs_mem( s1, s2, n1-1, n2-1, mem );
  for( int i=0; i< n1; i++ ) {
    for( int j=0; j<n2; j++ ) {
      cout << mem[i][j] << " ";
    }
    cout << "\n";
  }

  return mem[n1-1][n2-1];
}

int main() {
  string s1 = "GAPXBYA";
  string s2 = "GPXBBACP";
  cout << "Longest common subsequence " << lcs( s1, s2 ) << "\n";

  return 0;
}

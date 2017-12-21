#include<stdio.h>
#include<iostream>
using namespace std;

int lis_mem( int arr[], int size, int mem[] ) {
  mem[0]=1;

  for( int i = 0; i < size; i++ ) {
    int max = mem[ i ];
    for( int j = 0; j < i; j++ ) {
      if( arr[ j ] < arr[ i ] && 1 + mem[ j ] > max ) {
	max = 1 + mem[ j ];
      }
    }
    mem[ i ] = max;
  }

  return mem[ size - 1 ];
}

int lis( int arr[], int size ) {
  int mem[ 100 ] = { -1 };
  return lis_mem( arr, size, mem );
}

int main() {
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  int size = sizeof( arr )/sizeof( arr[ 0 ] );
  cout << " lis is: " << lis( arr, size ) << "\n"; 
  return 0;
}

#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;


int main() {
  string s1 = "GGGGrrrrrrrt";
  int n = s1.length();
  string s2 = "";
  int count = 1;
  for( int i=0; i<n; i++ ) {

    while( i+1 < n && s1[ i ] == s1[ i+1 ] ) {
      count++;
      i++;
    }
    s2 = s2 + to_string( count ) + s1[ i ];
    count = 1;

    /*if( s1[ i ] != s[ j ] ) {
      s2 = s2 + to_string( count ) + s[ j ];
      j = j+1;
      s[ j ] = s1[ i ];
      count = 1;
    } else {
      count++;
      }*/
  }
  cout << s1 << "\n";
  cout << s2 << "\n";
  return 0;
}

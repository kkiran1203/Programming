#include<stdio.h>
#include<iostream>

using namesoace std;


int main() {
  vector<int> x, vector<int> y;
  int dotproduct = DotProduct(x,y);
  return 0;
}

int DocProduct( vector<int> x, vector<int> y) {
  vector<int> result;
  for( int i=0; i<x.size(); i++ ) {
    int val = x[i] * y[i];
    result.push_back( val );
  }
  return result;

}

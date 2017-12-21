#include<stdio.h>
#include<iostream>

using namespace std;

void reverseWords(string &s) {
  int len = s.length();
  for( int i=0; i<len/2; i++ ) {
    char temp = s[i];
    s[i] = s[len-1-i];
    s[len-1-i] = temp;
  }
  string x = "";
  int next_start = 0;
  for( int i=0; i<len; i++ ) {
    if( i<len && s[i+1] == ' ' ){
      cout << " " << i << "  nextstart " << next_start << "\n";
      for( int j = next_start; j<=next_start + ( i - next_start )/2 ; j++ ) {
	char temp = s[j];
	s[j] = s[ next_start+i-j ];
	s[next_start+i-j] = temp;
      }
      next_start = i+2;
    } else if( i==len-1 ) {
      for( int j = next_start; j<=next_start+( i - next_start )/2; j++ ) {
	char temp = s[j];
	s[j] = s[ next_start+i-j ];
	s[next_start+i-j] = temp;
      }
    }
  }
  cout << s << "\n";
}


int main() {
  string s = "a b";
  reverseWords(s);
  cout << s << "\n";
  return 0;
}

#include<stdio.h>
#include<cstring>
#include<string.h>
#include<iostream>
#include<map>

using namespace std;

string convertRomanToInteger(string s){
  map<char, int> mapping;
  mapping['I'] = 1;
  mapping['V'] = 5;
  mapping['X'] = 10;
  mapping['L'] = 50;
  mapping['C'] = 100;
  mapping['D'] = 500;
  mapping['M'] = 1000;
  
  int n = s.length();
  int num = 0;
  int k = n-1;
  string romanString = "";
  string firstString = "";
  for( k=n-1; k>=0; k-- ) {
    if(s[k] == ' ' ) {
      break;
    }
    romanString = s[k] + romanString;
  }

  for( int i=0; i<k; i++ ) {
    firstString += s[i];
  }

  n = romanString.size();
  
  for( int i=0; i<n; i++ ) {
    if( i+1 < n && mapping[romanString[i+1]] > mapping[romanString[i]] ) {
      num -= mapping[romanString[i]];
    } else{
      num += mapping[romanString[i]];
    }
  }
  firstString += " ";
  firstString += to_string(num);
  
  return firstString;

}

bool compareNat(const string& a, const string& b){
  int n1 = a.size();
  int n2 = b.size();
  string first1 = "";
  string first2 = "";
  string num1 = "";
  string num2 = "";
  int k=n1-1;
  for( k=n1-1; k>=0; k-- ) {
    if(a[k] == ' ' ) {
      break;
    }
    num1 = a[k] + num1;
  }
  for(int i=0; i<k; i++ ) {
    first1 += a[i];
  }

  int k=n2-1;
  for( k=n2-1; k>=0; k-- ) {
    if(b[k] == ' ' ) {
      break;
    }
    num2 = b[k] + num2;
  }
  for(int i=0; i<k; i++ ) {
    first2 += b[i];
  }
  if( first2 > first1 ) {
    return true;
  } else if( first2 < first1 ) {
    return false;
  } else {
    if( num1 >= num2 ) {
      return true;
    } else {
      return false;
    }
  }
  

}

int main() {
  string s = "Albert XII";

  s = convertRomanToInteger(s);
  
  cout << s << "\n";
  return 0;
}



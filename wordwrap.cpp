#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

int wordwrap( int arr[], int N, int line ) {
    int ww[N][N];
    for( int i=0; i<N; i++) {
        int words = 0;
	int k = 0;
        for( int j=0; j<N; j++) {
	  if( j<i) {
	    ww[i][j] = INT_MAX;
	    continue;
	  }
	  words += arr[j] + k;
	    k++;
            if( words > line ) {
                ww[i][j] = INT_MAX;
            } else {
                ww[i][j] = pow( line - words, 3 );
            }
        }
    }
    for( int i=0; i<N; i++ ) {
      for( int j=0; j<N; j++ ) {
	cout << ww[i][j] << "  ";
      }
      cout << "\n";
    }
    int cost[N];
    cost[ 0 ] = pow( line - arr[0], 3);
    for( int j=1; j<N; j++ ) {
        int min = INT_MAX;
        for( int i=0; i<=j ; i++) {
	  if( i == 0 ) {
	    if( ww[i][j]!=INT_MAX && min > ww[i][j]) {
	      min = ww[i][j];
	    }
	  }
            if( cost[i-1] != INT_MAX && ww[i][j]!=INT_MAX &&
		min > cost[i-1] + ww[i][j]) {
                min = cost[i-1] + ww[i][j];
            }
        }
        cost[j] = min;
    }
    for( int i=0;  i<N; i++ ) {
      cout << cost[i] << "  ";
    }
    cout << "\n";
    return cost[N-1];
}

int main() {
	//code
	int T;
	cin >> T;
	for( int i=0; i<T; i++ ) {
	    int N;
	    cin >> N;
	    int words[N];
	    for( int j=0; j<N; j++ ) {
	        cin >> words[j];
	    }
	    int line_len;
	    cin >> line_len;
	    int cost = wordwrap( words, N, line_len );
	    cout << cost << "\n";
	    
	}
	return 0;
}

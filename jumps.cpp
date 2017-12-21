#include <iostream>
#include <limits.h>
using namespace std;

int getMinSteps( int arr[], int start, int N ) {
    if( start == N ) {
        return 0;
    }
    int min = INT_MAX;
    if( arr[start] == 0 ) {
      return min;
    }
    if( arr[start] > N-start-1 ) {
      return 1;
    }
    for( int i=1; i<=arr[start]; i++ ) {
        if( start+i >= N ) {
	  //continue;
	    break;
        }
        int x = getMinSteps( arr, start+i, N);
        if( 1+x < min && x != INT_MAX ) {
            min = 1+x;
        }
    }
    return min;
}

int jumps( int arr[], int start, int N, int temp[] ) {
  temp[N-1] = 0;

  for( int i=N-2; i>=0; i-- ) {
    if( arr[i] == 0 ) {
      cout << " value 0 " << i << "  " << arr[i] << "\n";
      temp[i] = INT_MAX;
    } else {
      if( i + arr[i] >= N-1 ) {
	cout << " value i + arr[i] " << i << "\n";
	temp[ i ] = 1;
      } else {
	int min = INT_MAX; 
	for( int j=1; j<=arr[i]; j++ ) {
	  if( i+j >=N ) {
	    break;
	  }
	  if( min > temp[ i+j ] ) {
	    min = temp[i+j];
	  }
	}
	if( min != INT_MAX ) {
	  cout << " value  " << i << "\n";
	  temp[i] = 1 + min;
	}
      }

    }
  }
  for( int i=0; i<N; i++ ) {
    cout << " " << temp[i];
  }
  cout << "\n";
  return temp[0];

}

int main() {
	//code
	int T;
	cin >> T;
	for( int i=0; i<T; i++ ) {
	    int N;
	    cin >>N;
	    int arr[N];
	    for( int j=0; j<N; j++ ) {
	        cin>>arr[j];
		cout << arr[j] << " ";
	    }
	    cout << "\n";
	    int temp[N];
	    int minSteps = jumps(arr,0,N, temp);
	    cout << minSteps << "\n";
	    minSteps = getMinSteps(arr,0,N);
	    cout << minSteps << "\n";
	}
	return 0;
}

#include <stdio.h>
#include <iostream>

using namespace std;

int max( int a, int b) {
    if(a>b) {
        return a;
    }
    return b;
}

string lcs(string s1, string s2, int n1, int n2) {
    int mem[n1][n2];
    if(s1[0] == s2[0]) {
        mem[0][0] = 1;
    } else {
        mem[0][0] = 0;
    }
    for( int i=1; i<n1; i++ ) {
        if( s2[0] == s1[i] ) {
            if(mem[i-1][0] == 0 ) {
                mem[i][0] = 1;
            } else {
                mem[i][0] = mem[i-1][0];
            }
        } else {
            mem[i][0] = mem[i-1][0];
        }
    }
    for( int i=1; i<n2; i++ ) {
        if( s1[0] == s2[i] ) {
            if(mem[0][i-1] == 0 ) {
                mem[0][i] = 1;
            } else {
                mem[0][i] = mem[0][i-1];
            }
        } else {
            mem[0][i] = mem[0][i-1];
        }
    }
    string temp_str = "";
    for( int i=1; i<n1; i++ ) {
        for( int j=1; j<n2; j++ ) {
            if(s1[i] == s2[j]) {
                mem[i][j] = 1+mem[i-1][j-1];
            } else {
                mem[i][j] = max( mem[i-1][j], mem[i][j-1]);
            }
        }
    }
    
    int i=n1-1;
    int j=n2-1;
    int len = mem[i][j];
    while( j>=0 && i>=0 && len > 0 ) {
        if( s1[i] == s2[j] ) {
            temp_str = s1[i] + temp_str;
            len--;
            i--;
            j--;
        } else {
            if(mem[i-1][j] > mem[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    if(mem[0][0] == 1 and len ==1 ) {
        temp_str = s1[0] + temp_str;
    }
    cout << "lcs is: " << mem[n1-1][n2-1] << "  " << temp_str << "\n";

    return temp_str;

}

string scs( string s1, string s2 ) {
    int n1 = s1.length();
    int n2 = s2.length();
    
    string seq = lcs(s1, s2, n1, n2);
    int i=0;
    int j=0;
    int k=0;
    int n3 = seq.length();
    string com_seq = "";
    cout << s1 << "   " << s2 << "   " << seq << "\n";
    while( i<n1 && j<n2 && k<n3 ) {
        if( s1[i] == s2[j] ) {
            if( s1[i] == seq[k]) {
                com_seq += seq[k];
                i++;
                j++;
                k++;
            } else {
	      com_seq += s1[i];
	      com_seq += s2[j];
	       i++;
	       j++;
	    }
        } else {
            if(s1[i] == seq[k] ) {
                com_seq += s2[j];
		j++;
            } else if(s2[j] == seq[k]) {
                com_seq += s1[i];
                i++;
            } else {
	      com_seq += s1[i];
	      com_seq += s2[j];
                i++;
                j++;
            }
        }
    }
    return com_seq;
}

int main() {
	//code
	int T;
	/*cin >> T;
	for( int i=0; i<T; i++ ) {
	    string s1, s2;
	    cin >> s1;
	    cin >> s2;
	    string seq = scs(s1, s2);
	    cout << seq;
	    }*/
	string s1 = "aggtab";
	string s2 = "gxtxayb";
	cout << " scs " << scs(s1,s2) << "\n"; 
	return 0;
}

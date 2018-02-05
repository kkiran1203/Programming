Given two strings S and T, determine if they are both one edit distance apart.

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        if( abs(n-m) > 1 ) {
            return false;
        }
        int dist = abs(n-m);
        int len = min(n, m);
        if( dist == 1 ) {
            string large = "";
            string small = "";
            if( n>m ) {
                large = s;
                small = t;
            } else {
                large = t;
                small = s;
            }
            
            for( int i=0; i<large.length(); i++ ) {
                string l = large;
                l.erase(l.begin()+i);
                if( l == small ) {
                    return true;
                }
            }
            
        } else {
            for( int i=0; i<len; i++ ) {
                if( s[i] != t[i] ) {
                    dist++;
                    if( dist > 1 ) {
                        //cout << "from here\n";
                        return false;
                    }
                }
            }
            return dist==1 ? true:false;
        }
        return false;
    }
};
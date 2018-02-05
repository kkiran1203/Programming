There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]


class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int> degree;
        unordered_map<char, unordered_set<char>> m;
        for( int i=0; i<n; i++ ) {
            for( int j=0; j<words[i].length(); j++ ) {
                if( degree.find(words[i][j]) == degree.end() ){
                    cout << words[i][j] << endl;
                    degree[words[i][j]] = 0;
                }
            }
        }
        
        for( int i=0; i<n-1; i++ ) {
            string w1 = words[i];
            string w2 = words[i+1];
            int length = min(w1.length(), w2.length());
            bool flag = false;

            for( int j=0; j<length; j++ ) {
                if( w1[j] != w2[j] ) {
                    if( m.find(w1[j]) != m.end() ) {
                        if( m[w1[j]].find(w2[j]) == m[w1[j]].end() ) {
                            m[w1[j]].insert(w2[j]);
                            degree[w2[j]]++;
                        }
                    } else {
                        m[w1[j]].insert(w2[j]);
                        degree[w2[j]]++;
                    }
                    flag = true;
                    break;
                }
                if( flag ) {
                    break;
                }
            }
        }
        cout << endl;
        queue<char> q;
        for( auto iter=degree.begin(); iter != degree.end(); iter++ ) {
            if( iter->second == 0 ) {
                cout << iter->first << endl;
                q.push(iter->first);
            }
        }
        
        string result = "";
        while( !q.empty() ) {
            char c = q.front();
            q.pop();
            result += c;
            if( m.find(c) != m.end() ) {
                for( auto it = m[c].begin(); it != m[c].end(); it++ ) {
                    degree[*it]--;
                    if(degree[*it]==0) {
                        q.push(*it);
                    }
                }
            }
        }
        return result.size() == degree.size() ? result:"";
        
    }
};
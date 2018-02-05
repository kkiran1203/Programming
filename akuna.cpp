
// A C++ program to check if four given points form a square or not.
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<string>
#include<queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void allCombinations(string s)
{
	int size = s.size();
	int i=0;

	while(s[0] == ' ')
		s.erase(0, 1);

	string str = "";
	while(s[i] != ' ' && i<size)
	{
		str += s[i];
		i++;
	}
    cout<<str<<endl;
	i++;
	string integer = "";
	while(s[i] != ' ' && i<size)
	{
		integer += s[i];
		i++;
	}
    
	int limit = stoi(integer);
    cout<<limit<<endl;
	queue<string> q;

	for(int i=0; i<str.length(); i++)
	{
		string temp = "";
		temp += str[i];
		q.push(temp);
	}

	vector<string> res;
    
	while( !q.empty())
	{
		int n = q.size();
		set<string> st;
		for(int i=0; i<n; i++)
		{
			string t1 = q.front();
			q.pop();

			if(t1.size() == limit)
			{
				res.push_back(t1);
			}
			else
			{
			    
				for(int i=0; i<str.length(); i++)
				{
					string t2 = t1;
					t2 += s[i];
					st.insert(t2);
				}
			}
		}
		for(auto it = st.begin(); it != st.end(); it++)
		{
		    cout<<*it<<" ";
			q.push(*it);				
		}
	}

	for(auto x : res)
	{
		cout<<x<<" ";
	}

}


int main()
{
	allCombinations("oopp 3");
	return 0;
}
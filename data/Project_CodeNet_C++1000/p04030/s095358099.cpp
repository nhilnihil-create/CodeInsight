#include <bits/stdc++.h>
using namespace std;

int main () {
	string s;
	
	cin>>s;
	int x = s.length();
	
	vector<char>insert;
	
	for(int i=0; i<x; i++) {
		if(s[i] != 'B') {
			insert.push_back(s[i]);
		} else if( !insert.empty()){
			insert.pop_back();
		}
	}
	
	for(int i=0; i<insert.size(); i++) {
		cout<<insert[i];
	}cout<<endl;
	
}
#include <bits/stdc++.h>
using namespace std;
int main(){
	
	string s;
	cin >> s;
	
	vector <char> v;
	
	for(int i = 0; i < s.size(); i ++){
		if(s[i] == 'B'){
			if(!v.empty()){
				v.pop_back();
			}
			continue;
		}
		
		v.push_back(s[i]);
	}
	
	for(int i = 0; i < v.size(); i ++){
		cout << v.at(i);
	}
	
	return 0;
}

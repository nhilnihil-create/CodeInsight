#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	string t;
	set<char>s;
	cin>>t;
	for(char c:t){
		s.insert(c);
	}
	cout<<(sz(t)==sz(s)?"yes":"no");


	
	
}
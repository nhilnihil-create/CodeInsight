#include <bits/stdc++.h>
using namespace std;

int main (){
	int n,k;
	
	cin>>n>>k;
	string s;
	
	vector<string>str;
	
	
	for(int i=0; i<n; i++) {
		cin>>s;
		str.push_back(s);
	}
	
	sort(str.begin(), str.end());
	
	for(int i=0; i<n; i++) {
		cout<<str[i];
	}cout<<"\n";
}
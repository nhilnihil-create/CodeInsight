#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	set<int>s;
	set<int>::iterator it; 
	while(n--){
		int a;
		cin>>a;
		it = s.find(a);
		if(it!=s.end()) s.erase(it);
		else s.insert(a);
	}
	cout<<s.size();	
}
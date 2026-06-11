#include<bits/stdc++.h>
using namespace std;

#define int long long 
vector<int> v;

void solve(int n){
	if(n==0) return ;
	if(n%2){
		solve(n/2);
		v.push_back(v.size());
	}
	else{
		solve(n-1);
		vector<int> g;g.push_back(v.size());
		for(int i=0;i<v.size();i++) g.push_back(v[i]);
		v=g;
	}
}
signed main(){
	int n;
	cin>>n;
	solve(n);
	
	cout<<v.size()*2<<"\n";
	for(int i=0;i<v.size();i++) cout<<v[i]+1<<" ";for(int i=0;i<v.size();i++) cout<<i+1<<" ";
		
	
	return 0;
}
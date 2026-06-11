#include <bits/stdc++.h>
using namespace std; 
int d[100010],n;
vector<int>e[100010];
void dfs(int a){
	if(e[a].empty())return;
	for(int i=0;i<e[a].size();i++)dfs(e[a][i]);
	vector<int>tp;
	for(int i=0;i<e[a].size();i++){
		tp.push_back(d[e[a][i]]);
	}
	sort(tp.begin(),tp.end());
	int mx=0,sz=tp.size();
	for(int i=0;i<sz;i++){
		mx=max(mx,tp[i]+sz-i);
		
	}
	d[a]=mx;
	return;
}
int main() { 
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		int a;
		cin>>a;
		e[a].push_back(i+1);
	}
	dfs(1);
	cout<<d[1]<<endl;
    return 0; 
}/*
*/
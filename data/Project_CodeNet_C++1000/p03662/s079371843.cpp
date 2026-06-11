/*
author:Manson
date:7.7.2018
theme:
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n;
vector<int>g[N*2];
int d1[N],d2[N];

void dfs(int rt,int fa,int d,int dict[]){
	dict[rt] = d;
	for(int x :g[rt]){
		if(x != fa){
			dfs(x,rt,d+1,dict);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int u,v;
	while(cin>>n){
		for(int i = 0;i < n;i++){
			g[i].clear();
		}
		for(int i = 0;i < n-1;i++){
			cin>>u>>v;
			u--;
			v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(0,-1,0,d1);
		dfs(n-1,-1,0,d2);
		int ans = 0;
		for(int i = 0;i < n;i++){
			if(d1[i] <= d2[i]){
				ans++;
			}
			else{
				ans--;
			}
		}
		if(ans > 0){
			cout<<"Fennec"<<endl;
		}
		else{
			cout<<"Snuke"<<endl;
		}
	}
	
	return 0;
}

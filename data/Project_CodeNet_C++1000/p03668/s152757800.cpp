#include<bits/stdc++.h>
using namespace std;

int SG[100001];

vector<int> e[100001];

void dfs(int x,int p){
	for(int it:e[x])
		if(it!=p){
			dfs(it,x);
			SG[x]^=(1+SG[it]);
		}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,e[u].emplace_back(v),e[v].emplace_back(u);
	dfs(1,0);
	if(SG[1])
		cout<<"Alice"<<endl;
	else
		cout<<"Bob"<<endl;
}

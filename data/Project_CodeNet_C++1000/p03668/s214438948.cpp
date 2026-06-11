#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

int dfs(auto &E,int now,int p){
	int ret = 0;
	for(int i=0;i<E[now].size();i++){
		if(E[now][i]==p)continue;
		ret ^= dfs(E,E[now][i],now);
	}
	return ret+1;
}

int main(){
	
	int N;
	cin>>N;
	
	vector<vector<int>> E(N,vector<int>());
	
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	if(dfs(E,0,-1)==1)cout<<"Bob"<<endl;
	else cout<<"Alice"<<endl;
	
	return 0;
}
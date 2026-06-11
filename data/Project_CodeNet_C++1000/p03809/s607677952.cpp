#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 10000000000000000

bool f = true;

void dfs(vector<long long> &A,vector<vector<int>> &E,int now,int parent){
	long long sum = 0;
	long long maxi = 0;
	int cnt = 0;
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(to==parent)continue;
		dfs(A,E,to,now);
		sum += A[to];
		maxi = max(maxi,A[to]);
		cnt++;
	}
	
	if(cnt==0)return;
	if(cnt==1){
		if(A[now]!=sum)f=false;
		return;
	}
	
	if(sum<A[now]){
		f=false;
		return;
	}
	
	long long x = sum-A[now];
	A[now] -= x;
	
	if(sum-maxi<x){
		f=false;
		return;
	}
	if(x*2>sum){
		f=false;
		return;
	}
	
	if(now==0&&A[now]!=0)f=false;
	
}

int main() {
	
	int N;
	cin>>N;
	
	vector<long long> A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	
	vector<vector<int>> E(N,vector<int>());
	
	for(int i=0;i<N-1;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	dfs(A,E,0,-1);
	
	if(f)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
    return 0;
}

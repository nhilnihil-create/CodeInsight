/******************
*  Author: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int minDis[100005];
int color[100005];
int v[100005];
int d[100005];
int c[100005];

void dfs(int node,int Dleft,int Cin){
	if(Dleft<=minDis[node])
		return ;
	minDis[node]=Dleft;
	if(color[node]==0)
		color[node]=Cin;
	for(int i=0;i<adj[node].size();i++){
		dfs(adj[node][i],Dleft-1,Cin);
	}
}

int main(){

	int N,M,Q;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		minDis[i]=-1;
	}
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin>>Q;
	for(int i=0;i<Q;i++){
		scanf("%d%d%d",v+i,d+i,c+i);
	}
	for(int i=Q-1;i>=0;i--){
		dfs(v[i]-1,d[i],c[i]);
	}
	for(int i=0;i<N;i++){
		cout<<color[i]<<endl;
	}

	return 0;
}

#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef pair<int,int>P;

vector<int>E[200000];

int dfs(int v,int p){
	int x=0;
	for(int u:E[v]){
		if(u==p)continue;
		x^=dfs(u,v);
	}
	if(v==0)return x;
	return x+1;
}
int main(){
	int n;scanf("%d",&n);
	rep(i,n-1){
		int a,b;scanf("%d%d",&a,&b);a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	puts(dfs(0,-1)?"Alice":"Bob");
}
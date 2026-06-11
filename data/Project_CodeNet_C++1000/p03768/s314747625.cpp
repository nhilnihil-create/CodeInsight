#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
vector<int> adj[100005];
int minDis[100005],color[100005],v[100005],d[100005],c[100005],N,M,Q;
void dfs(int node, int Dleft, int Cin){
	if(Dleft <= minDis[node]) return;
	minDis[node] = Dleft;
	if(color[node] == 0) color[node] = Cin;
	rep(i,0,adj[node].size()){
		int to=adj[node][i];
		dfs(to, Dleft-1, Cin);
	}
}
int main()
{
	scanf("%d%d", &N, &M);
	rep(i,0,N) minDis[i]=-1;
	rep(i,0,M)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	scanf("%d", &Q);
	rep(i,0,Q) scanf("%d%d%d", v+i, d+i, c+i);
	rrep(i,Q,0) dfs(v[i]-1, d[i], c[i]);
	rep(i,0,N) printf("%d\n", color[i]);
}
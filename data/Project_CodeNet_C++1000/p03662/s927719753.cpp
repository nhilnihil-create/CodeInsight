#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
vector<int>edge[100005];
int dist[2][100005];
void dfs(int v,int u,int d,int id){
	dist[id][v] = d;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v,d+1,id);
	}
}
int main(){
	cin >> n;
	repn(i,n-1){
		int a,b; cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1,0,0);
	dfs(n,-1,0,1);
	
	int cnt = 0;
	
	repn(i,n){
		if(dist[0][i] <= dist[1][i]) cnt++;
		else cnt --;
	}
	puts(cnt > 0?"Fennec":"Snuke");
}
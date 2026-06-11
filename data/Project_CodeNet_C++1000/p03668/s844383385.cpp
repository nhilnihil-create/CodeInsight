#include <bits/stdc++.h>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define mod 1000000007
int n;
vector<int>edge[1000005];
int dfs(int v,int u){
	vector<int>vec; int X = 0;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		int Y = dfs(edge[v][i],v);
		vec.pb(Y); X^=(Y+1); 
	}
	return X;
}
int main(){
	cin >> n ;
	for(int i=1;i<n;i++){
		int a,b; cin >> a >> b;
		edge[a].pb(b); edge[b].pb(a);
	}
	if(dfs(1,-1)) puts("Alice"); else puts("Bob");
}
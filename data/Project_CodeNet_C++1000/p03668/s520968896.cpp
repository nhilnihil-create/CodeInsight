#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define pw(x) (1<<(x))
#define inf 1000000005
#define MOD 1000000007 
#define N 150005
#define M 1000003
#define LOG 20
#define KOK 250
#define EPS 0.0000001
using namespace std;

vector<int> g;
vector<vector<int>> v;

void dfs(int node,int ata) {

	for(int i:v[node]) {

		if(i==ata) continue ;

		dfs(i,node);

		g[node]^=(g[i]+1);

	}

}

int main() {

	int n;

	scanf("%d",&n);

	g=vector<int>(n+1,0);
	v=vector<vector<int>>(n+1);

	for(int i=1;i<n;i++) {

		int x,y;

		scanf("%d %d",&x,&y);

		v[x].pb(y);
		v[y].pb(x);

	}

	dfs(1,0);

	printf(g[1]?"Alice":"Bob");

}
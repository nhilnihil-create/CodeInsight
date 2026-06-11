#include <bits/stdc++.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,P> PP;

//-----------------------------------------------------------------------------

int n,root;
ll stone[100000];
vector<int> G[100000];

void dfs(int v,int prv) {
	ll child_sum=0,ma=-1;
	if((int)G[v].size()==1) {
		return;
	}
	REP(i,(int)G[v].size()) {
		int u=G[v][i];
		if(u==prv) continue;
		dfs(u,v);
		child_sum+=stone[u];
		ma=max(ma,(ll)stone[u]);
	}
	if(stone[v]*2<child_sum||stone[v]>child_sum||stone[v]<ma) {
		cout<<"NO"<<endl;
		exit(0);
	}
	stone[v]=2*stone[v]-child_sum;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n;
	REP(i,n) cin>>stone[i];
	REP(i,n-1) {
		int a,b;cin>>a>>b;
		a--,b--;
		G[a].pb(b),G[b].pb(a);
	}
	if(n==2) {
		cout<<(stone[0]==stone[1]?"YES":"NO")<<endl;
		return 0;
	}
	while((int)G[root].size()==1) root++;
	dfs(root,-1);
	cout<<(stone[root]==0?"YES":"NO")<<endl;

	return 0;
}

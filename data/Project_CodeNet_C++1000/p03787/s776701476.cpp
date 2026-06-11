#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

vector<vector<ll>> adj;
vector<ll> col;
vector<bool> used;

ll dfs(ll pos, bool& flag) {
	used[pos]=true;
	ll cnt=1;
	REP(i,adj[pos].size()) {
		if(used[adj[pos][i]]) {
			if(col[adj[pos][i]]==col[pos]) flag=true;
			continue;
		}
		col[adj[pos][i]]=!col[pos];
		cnt+=dfs(adj[pos][i],flag);
	}
	return cnt;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	adj.resize(n);
	col.resize(n);
	used.resize(n);
	REP(i,n) col[i]=-1;
	REP(i,n) used[i]=false;
	REP(i,m) {
		ll u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll ans=0;
	ll gr1=0; // 二部でない
	ll gr2=0; // 二部
	ll gr3=0; // 孤立
	REP(i,n) {
		if(!used[i]) {
			bool d=false;
			col[i]=0;
			ll tmp=dfs(i,d);
			if(tmp==1) {
				gr3++;
			} else {
				if(d) gr1++;
				else gr2++;
			}
		}
	}
	ans+=gr3*n+n*gr3-gr3*gr3;
	ans+=gr1*(gr1+gr2)+(gr1+gr2)*gr1-gr1*gr1;
	ans+=2*gr2*gr2;
	cout<<ans<<endl;
}

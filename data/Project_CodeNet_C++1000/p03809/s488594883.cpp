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

vector<ll> a;
vector<vector<ll>> adj;
ll dfs(ll pos, ll par) {
	if((ll)adj[pos].size()==1) return a[pos];
	ll sum=0;
	ll maxi=0;
	REP(i,(ll)adj[pos].size()) {
		if(adj[pos][i]==par) continue;
		ll buf=dfs(adj[pos][i],pos);
		if(buf==-1) return -1;
		sum+=buf;
		maxi=max(maxi,buf);
	}
	ll buf=0;
	if(maxi<=sum/2) {
		buf=sum/2;
	} else {
		buf=(sum-maxi);
	}
	if(sum<a[pos]) return -1;
	if(sum-a[pos]<=buf) {
		return sum-(sum-a[pos])*2;
	} else {
		return -1;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	a.resize(n);
	adj.resize(n);
	REP(i,n) cin>>a[i];
	REP(i,n-1) {
		ll q,v;
		cin>>q>>v;
		q--;
		v--;
		adj[q].pb(v);
		adj[v].pb(q);
	}
	if(n==2) {
		if(a[0]==a[1]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		return 0;
	}
	ll ans=0;
	REP(i,n) {
		if((ll)adj[i].size()>1) {
			ans=dfs(i,-1);
			break;
		}
	}
	if(ans==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

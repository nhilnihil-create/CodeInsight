#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<int,int>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

vector<vector<ll>> child;

ll dfs(ll p) {
	vector<ll> v;
	REP(i,child[p].size()) v.pb(dfs(child[p][i]));
	sort(ALL(v)); reverse(ALL(v));
	ll ret = 0;
	REP(i,v.size()) {
		ret = max(ret, (i + 1) + v[i]);
	}
	return ret;
}

/* --------------------------------------- */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	child.resize(n);
	REP(i,n - 1) {
		ll a;
		cin >> a;
		a--;
		child[a].pb(i + 1);
	}
	cout << dfs(0) << endl;
	return 0;
}
/* --------------------------------------- */

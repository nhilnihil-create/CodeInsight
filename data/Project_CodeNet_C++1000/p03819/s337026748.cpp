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

ll N = 202020;
ll bit[202020];
void add(ll a, ll w) {
	a++;
	for (ll x = a; x <= N; x += x & -x) bit[x] += w;
}
ll sum(ll a) {
	a++;
	ll ret = 0;
	for (ll x = a; x > 0; x -= x & -x) ret += bit[x];
 return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	REP(i,N) bit[i]=0;
	ll n,m;
	cin>>n>>m;
	vector<P> gd(n);
	REP(i,n) cin>>gd[i].first>>gd[i].second;
	vector<pair<ll,P>> data(n);
	REP(i,n) {
		data[i].first=gd[i].second-gd[i].first+1;
		data[i].second=gd[i];
	}
	sort(ALL(data));
	vector<ll> ans(m,0);
	ll cur=0;
	FOR(i,1,m+1) {
		while(cur!=n&&data[cur].first<i) {
			add(data[cur].second.first,1);
			add(data[cur].second.second+1,-1);
			cur++;
		}
		ans[i-1]+=n-cur;
		ll pos=0;
		while(pos<=m) {
			ans[i-1]+=sum(pos);
			pos+=i;
		}
	}
	REP(i,m) cout<<ans[i]<<endl;
}

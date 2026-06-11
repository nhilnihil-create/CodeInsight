#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <fstream>
#include <ctime>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {1,-1,0,0,1,-1,1,-1};
ll dx[8] = {0,0,1,-1,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T> inline void print(T &a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
ll pcount(ll x) {return __builtin_popcountll(x);}
const int mod = 1e9 + 7;
//const int mod = 998244353;

int main(){
	ll n,L,t; cin >> n >> L >> t;
	vector<vpl> v(2);
	rep(i,n){
		ll x,w; cin >> x >> w; w--;
		v[w].emplace_back(x,i);
		v[w].emplace_back(x+L,i);
	}
	rep(i,2) sort(all(v[i]));
	ll inc = t / L;
	t %= L;
	vl ans(n);
	for(auto i : v[0]){
		if(i.first >= L) break;
		auto itr = lower_bound(all(v[1]), P(i.first+2*t, -inf));
		auto itr2 = lower_bound(all(v[1]), P(i.first, -inf));
		ll id = i.second + (itr-itr2) + inc * v[1].size();
		if(i.first+2*t >= 2*L){
			id += lower_bound(all(v[1]),P(i.first+2*t-2*L, -inf)) - v[1].begin();
		}
		ans[id%n] = (t + i.first) % L;
	}
	for(auto i : v[1]){
		if(i.first < L) continue;
		ll tmp = i.first - 2*t;
		ll d;
		if(tmp >= 0){
			auto itr = lower_bound(all(v[0]), P(i.first, -inf));
			d = itr - upper_bound(all(v[0]), P(tmp, inf));
		}else{
			d = lower_bound(all(v[0]), P(i.first, -inf)) - v[0].begin();
			d += v[0].end() - upper_bound(all(v[0]), P(2*L+tmp, inf));
		}
		d += inc * v[0].size();
		d %= n;
		ans[(i.second-d+3*n)%n] = (i.first - t) % L;
		//cout << (i.second-d+n)%n << "\n";
	}
	rep(i,n) cout << ans[i] << "\n";
}
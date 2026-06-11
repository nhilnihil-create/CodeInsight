
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(int i = m;i >= n;--i)
#define INF INT_MAX/2
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;
struct edge { ll from; ll to; ll cost; };

void err() {
	cout << "0" << endl;
	exit(0);
}
int main() {
	ll n;
	cin >> n;
	vector<ll>t;
	vector<ll>a;

	rep(i, 0, n) {
		ll T;
		cin >> T;
		t.pb(T);
	}
	rep(i, 0, n) {
		ll A;
		cin >> A;
		a.pb(A);
	}


	//0:確定1:未確定
	vector<pair<ll,ll>>td;
	vector<pair<ll,ll>>ad;

	rep(i, 0, n) {
		if (i == 0) {
			td.pb({t[i],0});
		}
		else {
			if (t[i] > t[i - 1]) {
				td.pb({ t[i],0});
			}
			else {
				td.pb({t[i],1});
			}
		}
	}



	rrep(i, n - 1, 0) {
		if (i == n - 1) {
			ad.pb({a[i],0});
		}
		else {
			if (a[i] > a[i + 1]) {
				ad.pb({a[i],0});
			}
			else {
				ad.pb({a[i],1});
			}
		}
	}
	reverse(all(ad));


	ll ans = 1;
	rep(i, 0, n){
		ll tf = td[i].first;
		ll ts = td[i].second;
		ll af = ad[i].first;
		ll as = ad[i].second;
		if (ts == 1 && as == 1) {
			ans *= min(tf, af);
		}else if (ts == 0 && as == 1) {
			if (af < tf) {
				err();
			}
		}
		else if (ts == 1 && as == 0) {
			if (tf < af) {
				err();
			}
		}
		else {
			if (tf != af) {
				err();
			}
		}
		ans %= MOD;
	}


	cout << ans << endl;
	return 0;
}
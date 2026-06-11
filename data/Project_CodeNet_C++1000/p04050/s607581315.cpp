#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m);
	REP(i,m) cin >> a[i];
	ll cnt = 0;
	REP(i,m) if(a[i] % 2) cnt++;

	if(n % 2) {
		if(cnt > 1) {
			cout << "Impossible" << endl;
			return 0;
		}
		if(m == 1 && a[0] == 1) {
			cout << 1 << endl;
			cout << 1 << endl;
			cout << 1 << endl;
			return 0;
		}
		if(m == 1) {
			cout << a[0] << endl;
			cout << 2 << endl;
			cout << a[0] - 1 << " " << 1 << endl;
			return 0;
		}
		ll buf = -1;
		vector<ll> ans1;
		vector<ll> ans2;
		REP(i,m) {
			if(a[i] % 2) buf = a[i];
			else ans1.pb(a[i]);
		}
		ans1.pb(buf);
		REP(i,m) {
			if(i == 0) {
				ans2.pb(ans1[i] - 1);
			} else if(i == m - 1) {
				ans2.pb(ans1[i] + 1);
			} else ans2.pb(ans1[i]);
		}
		DUMP(ans1);
		cout << (ll)ans2.size() << endl;
		DUMP(ans2);
		return 0;

	} else {
		if(cnt > 2) {
			cout << "Impossible" << endl;
			return 0;
		}
		if(cnt == 0) {
			vector<ll> ans1(m);
			REP(i,m) ans1[i] = a[i];
			vector<ll> ans2;
			ans2.pb(1);
			REP(i,m) {
				if(i != m - 1) ans2.pb(ans1[i]);
				else ans2.pb(ans1[i] - 1);
			}
			DUMP(ans1);
			cout << (ll)ans2.size() << endl;
			DUMP(ans2);
			return 0;
		}
		if(cnt == 2) {
			vector<ll> ans1;
			P buf = P(-1, -1);
			REP(i,m) {
				if(a[i] % 2) {
					if(buf.first == -1) buf.first = a[i];
					else buf.second = a[i];
				}
			}
			ans1.pb(buf.first);
			REP(i,m) if(a[i] % 2 == 0) ans1.pb(a[i]);
			ans1.pb(buf.second);
			vector<ll> ans2;
			REP(i,m) {
				if(i == 0) {
					ans2.pb(ans1[i] + 1);
				} else if(i == m - 1) {
					if(ans1[i] != 1) ans2.pb(ans1[i] - 1);
				} else {
					ans2.pb(ans1[i]);
				}
			}
			DUMP(ans1);
			cout << (ll)ans2.size() << endl;
			DUMP(ans2);
			return 0;
		}
	}
	return 0;
}

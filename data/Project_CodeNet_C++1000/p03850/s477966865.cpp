#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using pint=pair<int,int>;
using pll=pair<ll,ll>;
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
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<char> op(n);
	REP(i, n) {
		cin >> a[i];
		if(i != n - 1) cin >> op[i + 1];
	}
	vector<ll> revacm(n); revacm[n - 1] = a[n - 1];
	for(ll i = n - 2; i >= 0; i--) {
		revacm[i] = revacm[i + 1] + a[i];
	}
	ll ans = - INF * INF, sum = a[0];
	FOR(i, 1, n) {
		if(op[i] == '-') {
			sum += - a[i];
			ll tmp = 0, idx = -1;
			FOR(j, i + 1, n) {
				if(op[j] == '-') {
					idx = j;
					break;
				}
				tmp += a[j];
			}
			if(idx != -1) ans = max(ans, sum - tmp + revacm[idx]);
		} else {
			sum += a[i];
		}
	}
	ans = max(ans, sum);
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */

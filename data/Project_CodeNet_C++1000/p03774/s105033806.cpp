#include <bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)(x.size()))
#define FOR(i,s,n) for (ll i = (s); (i) < (n); ++i)
#define FORD(i,s,l) for (ll i = (s); (i) >= l; --i)
#define F first
#define S second
#define TC int __tc; cin >> __tc; FOR(case_num,1,__tc+1)
#define TEST(x,i) ((x)&(1ll<<(i)))
#define SET(x,i) ((x)|(1ll<<(i)))
#define FLIP(x,i) ((x)^(1ll<<(i)))
#define CLEAR(x,i) ((x)&~(1ll<<(i)))

const double pi = 4 * atan(1);
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MAXN = 200005;

ll x[55];
ll y[55];

ll cx[55];
ll cy[55];

ll dist(int i, int j) {
	return llabs(x[i]-cx[j])+llabs(y[i]-cy[j]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	
	cin >> n >> m;
	FOR(i,0,n) {
		cin >> x[i] >> y[i];
	}
	FOR(i,0,m) {
		cin >> cx[i] >> cy[i];
	}
	
	FOR(i,0,n) {
		int ans = 0;
		FOR(j,1,m) {
			if (dist(i,ans) > dist(i,j)) {
				ans = j;
			}
		}
		cout << ans+1 << "\n";
	}

}

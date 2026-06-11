#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

void solve_abc_d() {
	ll h, w;
	cin >> h >> w;

	ll c[101][101];
	ll n;
	cin >> n;
	V a(n);
	ll cnt = 0;
	rep(i, n) {
		cin >> a[i];
		rep(j, a[i]) {
			if (cnt / w % 2 == 0) {
				c[cnt / w][cnt % w] = i + 1;
			}
			else {
				c[cnt / w][w - 1 - cnt % w] = i + 1;
			}
			cnt++;
		}
	}

	rep(i, h){
		rep(j, w - 1) {
			cout << c[i][j] << " ";
		}
		cout << c[i][w - 1] << "\n";
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_d();

	return 0;
}

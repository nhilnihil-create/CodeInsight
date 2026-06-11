#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
vector<ll> v1, v2;
ll a[1 << 17],c[1<<17];
ll ans[1 << 17];
int main() {
	int n; ll l, t; cin >> n >> l >> t;
	ll r = t % l; ll d = t / l;
	rep(i, n) {
		ll x; int w; cin >> x >> w;
		c[i] = w;
		if (w == 1) {
			v1.push_back(-x);
			v1.push_back(-x + l);
			v1.push_back(-x + 2*l);
			v1.push_back(-x + 3*l);
			a[i] = x;
		}
		else {
			v2.push_back(x);
			v2.push_back(x + l);
			v2.push_back(x + 2*l);
			v2.push_back(x + 3*l);
			a[i] = -x;
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int l1 = v1.size()/2;
	int l2 = v2.size()/2;
	rep(i, n) {
		ll sum = 0;
		ll loc = 0;
		ll id;
		if (c[i] == 1) {
			sum += d * l2;
			sum += upper_bound(v2.begin(), v2.end(), a[i] + 2*r) - v2.begin();
			sum -= lower_bound(v2.begin(), v2.end(), a[i]) - v2.begin();
			loc = (a[i] + t) % l;
			id = (i + sum) % n;
		}
		else {
			sum += d * l1;
			sum += upper_bound(v1.begin(), v1.end(), a[i] + 2*r) - v1.begin();
			sum -= lower_bound(v1.begin(), v1.end(), a[i]) - v1.begin();
			loc = ((-a[i] - t) % l + l) % l;
			id = ((i - sum) % n + n) % n;
		}
		ans[id] = loc;
	}
	rep(i, n) {
		cout << ans[i] << endl;
	}
	return 0;
}

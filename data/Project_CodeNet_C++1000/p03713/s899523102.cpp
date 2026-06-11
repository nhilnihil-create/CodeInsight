#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	ll h, w;
	cin >> h >> w;
	ll ans = LINF;
	for (ll i = 1; i <= h; i++) {
		ll s1 = i * w;
		if (s1 >= h * w) break;
		ll s2 = (h - i) / 2 * w;
		ll s3 = (h - i) * w - s2;
		ll ds = max(s1, max(s2, s3)) - min(s1, min(s2, s3));
		ans = min(ans, ds);
		
		s2 = w / 2 * (h - i);
		s3 = (h - i) * w - s2;
		ds = max(s1, max(s2, s3)) - min(s1, min(s2, s3));
		ans = min(ans, ds);
	}

	for (ll i = 1; i <= w; i++) {
		ll s1 = i * h;
		if (s1 >= h * w) break;
		ll s2 = (w - i) / 2 * h;
		ll s3 = (w - i) * h - s2;
		ll ds = max(s1, max(s2, s3)) - min(s1, min(s2, s3));
		ans = min(ans, ds);
		
		s2 = h / 2 * (w - i);
		s3 = (w - i) * h - s2;
		ds = max(s1, max(s2, s3)) - min(s1, min(s2, s3));
		ans = min(ans, ds);
	}

	cout << ans << endl;
}
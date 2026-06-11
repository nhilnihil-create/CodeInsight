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
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	ll ans = max(0, v[0] - x);
	v[0] = max(0ll, v[0] - ans);
	rep(i,n-1) {
		ll sum = v[i] + v[i+1];
		if (sum > x) {
			ll sub = sum - x;
			ans += sub;
			v[i+1] = max(0ll, v[i+1] - sub);
		}
	}
	cout << ans << endl;
}
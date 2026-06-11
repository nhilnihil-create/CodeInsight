#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;
const ll oo = 1e18;

signed main()
{
	IO_OP;
	
	int n, x;
	cin >> n >> x;
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];	
	vi b = a;
	ll ans = oo;
	for(int i = 0; i < n; i++) {
		ll cur = (ll) i * x;
		for(int j = 0; j < n; j++) {
			b[j] = min(b[j], a[(i + j) % n]);
			cur += b[j];
		}
		ans = min(ans, cur);
	}	
	cout << ans << endl;

}

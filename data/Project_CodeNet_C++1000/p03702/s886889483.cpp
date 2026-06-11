// IOI 2021
 
#include <bits/stdc++.h>

using namespace std;

#define int ll
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9;
const int MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 2e5 + 5;

int H[N];

int32_t main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, a, b, sum = 0; cin >> n >> a >> b;
	for (int i = 0; i < n; i++) cin >> H[i];
	int dw = 0, up = INF;
	while (up - dw > 1) {
		int md = dw + up >> 1;
		int cnt = 0;
		for (int i = 0; i < n; i++) cnt += ((H[i] - min(H[i], md * b)) + (a - b - 1)) / (a - b);
		if (cnt > md) dw = md;
		else up = md;
	}
	cout << up << endl;

	return 0;
}

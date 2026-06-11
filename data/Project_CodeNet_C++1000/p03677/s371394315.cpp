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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

int a[N];

struct BIT {
	int bit[N];
	void add(int pos, int val) {
		pos++;
		for(; pos < N; pos += pos & -pos)
			bit[pos] += val;
	}
	int qry(int pos) {
		pos++;
		int ret = 0;
		for(;pos;pos -= pos & -pos)
			ret += bit[pos];
		return ret;
	}
} x, y;

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i], a[i]--;	
	int ans = 0, mx = 0;
	for(int i = 0; i < n - 1; i++) {
		ans += (a[i + 1] - a[i] + m) % m;
		if(a[i + 1] == a[i] + 1) continue;
		if(a[i + 1] > a[i]) {
			x.add(a[i] + 1, 1), x.add(a[i + 1] + 1, -1);
			y.add(a[i] + 1, -a[i]), y.add(a[i + 1] + 1, +a[i]);
		}
		else {
			x.add(a[i] + 1, 1), x.add((m - 1) + 1, -1);
			y.add(a[i] + 1, -a[i]), y.add((m - 1) + 1, +a[i]);

			x.add(0, 1), x.add(a[i + 1] + 1, -1);
			y.add(0, m-a[i]), y.add(a[i + 1] + 1, -m+a[i]);	
		}
	}
	for(int i = 0; i < m; i++) {
		mx = max(mx, x.qry(i) * i - x.qry(i) + y.qry(i));
	}

	cout << ans - mx << endl;

}




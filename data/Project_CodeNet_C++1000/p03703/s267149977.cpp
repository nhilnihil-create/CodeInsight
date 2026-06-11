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

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N], bit[N];

int qry(int pos) {
	int ret = 0;
	for(;pos;pos-=pos&-pos)
		ret += bit[pos];
	return ret;
}

void add(int pos) {
	for(;pos < N;pos += pos&-pos)
		bit[pos]++;
}

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	vi v;
	for(int i = 1; i <= n; i++) a[i] += a[i-1];
	for(int i = 0; i <= n; i++) a[i] -= i * k, v.PB(a[i]);
	sort(ALL(v));
	v.resize(unique(ALL(v))-v.begin());
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		int tt = lower_bound(ALL(v), a[i]) - v.begin() + 1;
		ans += qry(tt);
		add(tt);
	}
	cout << ans << endl;
}





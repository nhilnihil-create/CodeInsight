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

const int INF = 1e9 + 7, N = 1e5 + 7;

vi G[N];

int ans = 0, n, k;
int a[N];

int dfs(int u) {
	int mx = 0;
	for(int v:G[u]) {
		mx = max(mx, dfs(v) + 1);
	}
	if(mx == k - 1 && a[u] != 1) {
		ans++;
		mx = -1;
	}
	return mx;
}

signed main()
{
	IO_OP;
	
	cin >> n >> k;	
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(a[1] != 1) {
		ans++;
		a[1] = 1;
	}
	for(int i = 2; i <= n; i++) G[a[i]].PB(i);
	dfs(1);
	cout << ans << endl;


}




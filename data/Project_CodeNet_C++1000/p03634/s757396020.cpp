#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

vector<P> g[100005];
vector<ll> ans(100005);
vector<bool> vi(100005);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	rep(i, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	int q, k;
	cin >> q >> k;
	k--;
	queue<int> que;
	que.push(k);
	ans[k] = 0;
	vi[k] = true;
	while (que.size()) {
		int a = que.front(); que.pop();
		for (auto& c : g[a]) {
			if (vi[c.first]) continue;
			vi[c.first] = true;
			ans[c.first] = ans[a] + (ll)c.second;
			que.push(c.first);
		}
	}
	rep(ri, q) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		ll j_ans = ans[x] - ans[k];
		j_ans += ans[y] - ans[k];
		printf("%lld\n", j_ans);
	}
	return 0;
}

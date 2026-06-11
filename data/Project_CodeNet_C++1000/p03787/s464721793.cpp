#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define ll long long
#define pb push_back
#define mp make_pair

vec<vec<int>> edge;
vec<int> dp;
vec<int> score;

int dfs(int start)
{
	int ret = 1;
	dp[start] = 1;
	rep(i, edge[start].size()) {
		if (dp[edge[start][i]]) continue;
		ret += dfs(edge[start][i]);
	}
	return ret;
}

int odd(int start)
{
	int flag = 0;
	rep(i, edge[start].size()) {
		if (score[edge[start][i]]) {
			if ((score[start] - score[edge[start][i]]) % 2) continue;
			flag = 1;
			break;
		}
		score[edge[start][i]] = score[start] + 1;
		if (odd(edge[start][i])) {
			flag = 1;
			break;
		}
	}
	return flag;
}


int main(void)
{
	int n, m;
	cin >> n >> m;
	edge.resize(n);
	dp.resize(n);
	score.resize(n);
	rep(i, n) dp[i] = 0;
	rep(i, m) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		edge[l].pb(r);
		edge[r].pb(l);
	}

	ll ans = 0;
	ll left = 0;
	// vec<pair<ll, int>> keep; // first: size, second: odd
	ll count_odd = 0;
	ll count_even = 0;
	int next_dp = 0;
	while(next_dp < n) {
		int next = - 1;
		for (int i = next_dp; i < n; i++) {
			if (!dp[i]) {
				next = i;
				next_dp = i + 1;
				break;
			}
		}
		if (next < 0) break;

		int N = dfs(next);
		if (N == 1) {
			left++;
			continue;
		}
		rep(i, n) score[i] = 0;
		score[next] = 1;
		int flag = odd(next);
		if (flag) ans++;
		else ans += 2;
		if (flag) count_odd++;
		else count_even++;
	}
	ans += count_even * (count_even - 1) * 2 + count_even * count_odd * 2 + count_odd * (count_odd - 1);
	ans += left * left + left * (n - left) * 2;
	cout << ans << endl;
	return 0;
}
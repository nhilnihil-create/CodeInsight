#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define FF first
#define SS second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pie;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll LINF = 4e18;
const ll delta = 10289;

const int N = 1e5 + 20;
ll n , a[N], p[N], pre[N], suf[N], k, ans;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], p[i] = a[i];
	for (int i = 1; i <= n; i++) {
		p[i] += p[i - 1];
		pre[i] = pre[i - 1] + (a[i] > 0) * a[i];
	}
	for (int i = n; i >= 1; i--)
		suf[i] = suf[i + 1] + (a[i] > 0) * a[i];
	for (int i = 1; i <= n - k + 1; i++)
		ans = max({ans, p[i + k - 1] - p[i - 1] + pre[i - 1] + suf[i + k], pre[i - 1] + suf[i + k]});
	cout << ans << endl;
}


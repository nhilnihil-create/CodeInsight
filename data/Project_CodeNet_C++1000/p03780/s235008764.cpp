#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <set>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstring>

using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<string, string> sP;
typedef pair<ll, pair<ll, ll>> PP;

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int px[6] = { 0,1,-1,1,0,1 }, py[6] = { -1,-1,0,0,1,1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second



int main() {
	ll n, k, a[5010] = {0}, ans = 0;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)cin >> a[i];
	sort(a+1, a + n+1);
	int l = 0, r = n + 1, mid;
	while (r - l > 1) {
		mid = (r + l) / 2;
		bool dp[5010][5010] = { 0 };
		dp[0][0] = 1;
		for (int i = 1;i <= n;i++) {
			for (int j = 0;j <= k;j++) {
				if (dp[i - 1][j])dp[i][j] = 1;
				if (i == mid)continue;
				if (dp[i - 1][j] && j + a[i] <= k)dp[i][j + a[i]] = 1;
			}
		}
		bool fl = 0;
		for (int i = max(0LL,k - a[mid]);i < k;i++) {
			if (dp[n][i])fl = 1;
		}
		if (fl)r = mid;
		else l = mid;
	}
	for (int i = 1;i <= n;i++) {
		if (a[i] <= a[l])ans++;
	}
	cout << ans << endl;
	return 0;
}
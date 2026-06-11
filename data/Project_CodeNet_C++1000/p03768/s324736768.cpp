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

const ll mod = 1e4;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second


ll n, m, a, b, A[100010], B[100010], C[100010], q;
vector<ll>v[100010];
ll dp[100010][11];



int main() {
	cin >> n >> m;
	for (int i = 0;i <= n;i++) {
		for (int j = 0;j <= 10;j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0;i < m;i++){
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	cin >> q;
	for (int i = 1;i <= q;i++) {
		cin >> A[i] >> B[i] >> C[i];
		dp[A[i]][B[i]] = i;
	}
	for (int z = 0;z < 10;z++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= 10;j++) {
				if (dp[i][j] != -1) {
					for (auto u : v[i])dp[u][j - 1] = max(dp[u][j - 1], dp[i][j]);
				}
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		ll ans = 0;
		for (int j = 0;j <= 10;j++) {
			ans = max(ans, dp[i][j]);
		}
		cout << C[ans] << endl;
	}
	return 0;
}
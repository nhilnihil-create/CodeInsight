#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;
const int MAX_N = 100010;

bool cmp(P a, P b) { return a.second < b.second; }

int a[101], b[101];
int dp[101][101][10010];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	int n;
	cin >> n;

	ll cnt[10010] = {}, ans = 1;

	for (ll i = 2; i <= n; i++) {
		ll t = i;
		for (ll j = 2; j <= t; j++) {
			while (t > 0 && t % j == 0) {
				cnt[j]++;
				t /= j;
			}
		}
	}

	for (ll i = 0; i <= n; i++) {
		if (cnt[i] != 0) {
			ans *= cnt[i] + 1;
			ans %= mod;
		}
	}

	out(ans);

	return 0;
}
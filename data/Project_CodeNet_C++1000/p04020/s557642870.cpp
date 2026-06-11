#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) ((int) x.size())
#define all(x) (x).begin(), (x).end()
#define re return
#define mp make_pair
#define makeunique(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define endl '\n'

typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<string> vs;

template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }

const double pi = acos(-1.);
const ll inf = 1e18 + 7;
const int N = 3e5 + 17;

int n, m;
ll a[N], dp[N][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	dp[0][1] = -inf;
	for (int i = 0; i < n; i++) {
	    if (a[i] & 1) {
	    	if (dp[i][1] != -inf)
	    		dp[i + 1][0] = dp[i][1] + a[i] / 2 + 1;
	    	else dp[i + 1][0] = -inf;
	    	dp[i + 1][1] = max(dp[i][0], dp[i][1]) + a[i] / 2;
	    } else {
			dp[i + 1][0] = max(dp[i][0], dp[i][1]) + a[i] / 2;
			if (a[i])
				dp[i + 1][1] = max(dp[i][1] + (a[i] - 1) / 2 + 1, max(dp[i][1], dp[i][0]) + a[i] / 2 - 1);
			else dp[i + 1][1] = -inf;
	    }

//	    cout << i + 1 << " " << dp[i + 1][0] << " " << dp[i + 1][1] << endl;

	}
	cout << max(dp[n][0], dp[n][1]);
}

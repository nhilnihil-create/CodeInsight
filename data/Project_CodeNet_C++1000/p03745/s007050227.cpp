#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a[100005];
int dp[100005][2];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	const int INC = 0, DEC = 1;
	dp[1][INC] = dp[1][DEC] = 1;
	
	rep(i, 2, n + 1) {
		dp[i][INC] = min(dp[i - 1][INC], dp[i - 1][DEC]) + 1;
		dp[i][DEC] = min(dp[i - 1][INC], dp[i - 1][DEC]) + 1;
		if (a[i] <= a[i - 1])
			dp[i][DEC] = min(dp[i][DEC], dp[i - 1][DEC]);
		if (a[i] >= a[i - 1])
			dp[i][INC] = min(dp[i][INC], dp[i - 1][INC]);
	}

	cout << min(dp[n][INC], dp[n][DEC]) << endl;
}

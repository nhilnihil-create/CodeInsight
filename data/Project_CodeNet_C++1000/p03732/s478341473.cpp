#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, W;
	cin >> N >> W;



	int w[100], v[100];
	rep(i, N) cin >> w[i] >> v[i];
	int w0 = w[0];

	int dp[101][101][301] = {};
	rep(i, 101) {
		rep(j, 101) {
			rep(k, 301) {
				dp[i][j][k] = -1;
			}
		}
	}

	dp[0][0][0] = 0;

	rep(i, N) {
		rep(j, i + 1) {
			rep(k, 300) {
				if (dp[i][j][k] >= 0) {
					dp[i + 1][j + 1][k + w[i] - w0] = max(dp[i + 1][j + 1][k + w[i] - w0], dp[i][j][k] + v[i]);
					dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
				}
			}
		}
	}

	int kotae = 0;
	rep(j, N + 1) {
		rep(k, 301) {
			if ((ll)j * w0 + k <= W) {
				kotae = max(kotae, dp[N][j][k]);
			}
		}
	}
	co(kotae);

	Would you please return 0;
}
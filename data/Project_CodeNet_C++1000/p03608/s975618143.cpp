#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int INF = 1e8;

signed main() {
	int N, M, R;
	cin >> N >> M >> R;
	vector<int>r(R);
	rep(i, R) {
		int input;
		cin >> input;
		input--;
		r[i] = input;
	}
	vector<vector<int>>dp(N, vector<int>(N, INF));
	rep(i, N)dp[i][i] = 0;
	rep(i, M) {
		int A, B, C;
		cin >> A >> B >> C;
		A--; B--;
		dp[A][B] = C;
		dp[B][A] = C;
	}
	for (int k = 0; k < N; k++) { //経由する頂点
		for (int i = 0; i < N; i++) { //始点
			for (int j = 0; j < N; j++) { //終点
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	sort(r.begin(), r.end());
	int ans = INF;
	do {
		int dist = 0;
		for (int i = 1; i < R; i++)dist += dp[r[i - 1]][r[i]];
		ans = min(dist, ans);
	} while (next_permutation(r.begin(), r.end()));
	cout << ans;
}
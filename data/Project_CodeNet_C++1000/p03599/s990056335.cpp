
// C - Sugar Water

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

const int MAX = 4000;
bool dp[MAX][MAX]; // dp[a][b]: 水i(g), 砂糖j(g)の組み合わせがあれば1

int main() {
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;

	dp[0][0] = 1;

	for (int a=0; a<=F; a++) {
		for (int b=0; b<=F; b++) {
			if (dp[a][b] == 0) continue;

			if (a + 100*A + b <= F) {
				dp[a + 100*A][b] = 1;
			}

			if (a + 100*B + b <= F) {
				dp[a + 100*B][b] = 1;
			}

			if ((b + C) * (100 + E) <= E * (a + (b + C)) && a + (b + C) <= F) {
				dp[a][b+C] = 1;
			}

			if ((b + D) * (100 + E) <= E * (a + (b + D)) && a + (b + D) <= F) {
				dp[a][b+D] = 1;
			}
		}
	}

	int w = 100*A, s = 0;
	for (int a=0; a<=F; a++) {
		for (int b=0; b<=F; b++) {
			if (dp[a][b] == 0) continue;

			if (b * (w + s) > s * (a + b)) {
				w = a;
				s = b;
			}
		}
	}

	cout << w + s << " " << s << endl;

	return 0;
}
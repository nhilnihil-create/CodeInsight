
// C - Sugar Water

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

const int MAX = 4000;
bool dp[MAX][MAX]; // dp[a][b]: 水i(g), 砂糖j(g)の組み合わせがあれば1

int main() {
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;

	set<int> water;
	set<int> sugar;

	for (int i=0; i*100*A<=F; i++) {
		for (int j=0; j*100*B<=F; j++) {
			if ((i*100*A + j*100*B != 0) && (i*100*A + j*100*B <= F)) {
				water.insert(i*100*A + j*100*B);
			}
		}
	}

	for (int i=0; i*C<=F; i++) {
		for (int j=0; j*D<=F; j++) {
			if (i*C + j*D <= F) {
				sugar.insert(i*C + j*D);
			}
		}
	}

	int ans_w = 100*A;
	int ans_s = 0;
	for (int w : water) {
		for (int s : sugar) {
			if (s * (100 + E) > E * (w + s)) continue;
			if (w + s > F) continue;

			if (s * (ans_w + ans_s) > ans_s * (w + s)) {
				ans_w = w;
				ans_s = s;
			}
		}
	}

	cout << ans_w + ans_s << " " << ans_s << endl;

	return 0;
}
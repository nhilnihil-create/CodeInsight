#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>
#include<time.h>

#define DIV 998244353
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
	int sw = 0, s = 0;
	for (int i = 0; i * 100 * A <= F; i++) {
		int a = i * 100 * A;
		for (int j = 0; a + j * 100 * B <= F; j++) {
			int b = j * 100 * B;
			int sm = (i * A + j * B) * E;
			vector<bool> dp(sm + 1);
			dp[0] = true;
			int ts = 0;
			for (int k = 0; k < sm; k++) {
				if (dp[k]) {
					if (k + C <= sm) {
						dp[k + C] = true;
						if (a + b + k + C <= F) {
							ts = max(ts, k + C);
						}
					}
					if (k + D <= sm) {
						dp[k + D] = true;
						if (a + b + k + D <= F) {
							ts = max(ts, k + D);
						}
					}

				}
			}

			//printf("a+b+ts=%d ts=%d\n", a + b + ts, ts);

			if (s * (a + b + ts) <= ts * sw) {
				sw = a + b + ts, s = ts;
			}

		}
	}

	cout << sw << " " << s << endl;
}

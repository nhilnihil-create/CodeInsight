#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;


int main() {

	ll N, C, K;

	cin >> N >> C >> K;

	vector<ll>T(N);

	rep(i, N) {
		cin >> T[i];
	}

	sort(T.begin(), T.end());


	ll D, P = 0, count = 0;

	rep(i, N) {
		P++;
		if (i == 0) {
			D = T[i] + K;
		}

		if (P >= C || T[i] > D) {
			count++;
			P = 0;
			D = T[i] + K;
		}
		if (i == N - 1) {
			count++;
		}

	}
	count = min(N, count);

	cout << count;

	return 0;
}

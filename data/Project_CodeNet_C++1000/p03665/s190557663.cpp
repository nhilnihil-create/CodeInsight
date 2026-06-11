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
	ll N, P, ans, even = 0, odd = 0;
	cin >> N >> P;

	vector<ll>A(N);

	rep(i, N) {
		cin >> A[i];
		if (A[i] % 2 == 0) {
			even++;
		}
	}
	if (even == N) {
		if (P == 0) {
			ans = pow(2, N);
		}
		else {
			ans = 0;
		}
	}
	else {
		ans = pow(2, N - 1);
	}

	cout << ans;

	return 0;

}

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
	ll N, tmp;
	cin >> N;

	vector<ll> ans;
	vector<ll>::iterator it;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (i % 2 == 0) {
			ans.push_back(tmp);
		}
		else {
			it = ans.begin();
			it = ans.insert(it, tmp);
		}
	}

	if (N % 2 == 0) {
		for (ll i = 0; i < N; i++) {
			cout << ans[i] << " ";
		}
	}
	else
	{
		for (ll i = N - 1; i >= 0; i--) {
			cout << ans[i] << " ";
		}

	}
	return 0;
}
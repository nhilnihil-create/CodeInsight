#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstring>
#include <iomanip>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n, x[N];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}

	int place = 1;
	ll ans = 1;
	ll mod = 1e9 + 7;

	for (int i = 1; i <= n; i++) {
		if (x[i] >= 2 * (i - place) + 1) continue;
		ans *= ll(i - place + 1);
		ans %= mod;
		place++;
	}

	while (place <= n) {
		ans *= ll(n - place + 1);
		ans %= mod;
		place++;
	}

	cout << ans << endl;
	//system("pause");
	return 0;
}
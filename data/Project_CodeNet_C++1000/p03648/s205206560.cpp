#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
using namespace std;

using ll = long long;
int main() {

	ll K;
	cin >> K;
	for (int n = 50; n >= 2; n--) {
		vector<ll> ans(n);
		for (int i = 0; i < n; i++) {
			ans[i] = n - 1+ -K + (n + 1) * (K / n);
		}
		for (int i = 0; i < K%n; i++) {
			ans[i] += n + 1;
		}
		bool ok = true;
		for (int i = 0; i < n; i++)if (ans[i] < 0)ok = false;
		if (!ok)continue;
		cout << n << endl;
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		return 0;
	}
}


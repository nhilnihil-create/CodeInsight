#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
	long long mod = 1000000007ll;
	int N; scanf("%d", &N);
	long long ans = 1ll; int cnt = 0;
	for (int i = 0; i < N; ++i) {
		int x; scanf("%d", &x);
			while ((i - cnt) * 2 + 1 > x) {
				ans *= (long long) (i - cnt + 1);
				ans %= mod;
				cnt++;
			}
	}
	while (cnt < N) {
		ans *= (long long) (N - cnt);
		ans %= mod;
		cnt++;
	}
	cout << ans << endl;

	return 0;
}
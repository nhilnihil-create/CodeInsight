#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int M = 1000000000 + 7;
int n, a;

int main() {
	if (0) freopen("a.in", "r", stdin);
	scanf("%d", &n);
	ll ans = 1, cur = 1, cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		if (a >= cur)
			cur += 2, ++cnt;
		else {
			ans = (ans*(cnt + 1)) % M;
		}
	}
	while (cnt > 0)
		ans = (ans*cnt--) % M;
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;
bool x[N];
int main() {
	int n;
	scanf("%d", &n);
	int las = -1, ans = 1, cur = 0, cnt = 0;
	for (int i = 1; i <= n; ++ i) {
		int a;
		scanf("%d", &a);
		int old = las;
		//printf("%d\n", i - cnt);
		ans = 1LL * ans * (i - cnt) % MOD;
		if (a == las + 1) {
			cnt ++;
		}
		else {
			las += 2;
		}
	}
	cout << ans << endl;
}


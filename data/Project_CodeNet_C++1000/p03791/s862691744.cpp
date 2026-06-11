#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
int n;
int x[100003];

void proc() {
	scanf("%d", &n);
	int ans = 1, cnt = 1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
		ans = (long long)ans * cnt % MOD;
		if (x[i] >= 2 * (cnt - 1) + 1) {
			++cnt;
		}
	}
	printf("%d\n", ans);
}

int main() {
	proc();
	return 0;
}
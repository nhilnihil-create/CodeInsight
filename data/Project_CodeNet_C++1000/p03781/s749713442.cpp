#include <bits/stdc++.h>
#define ls (o << 1)
#define rs (o << 1 | 1)
#define mid ((L + R) >> 1)
using namespace std;
const int MAXN = 200100;
const int mod = 998244353;
typedef long long LL;
typedef pair<int, int> PII;
int n;
bool check(int m) { return 1LL * m * (m + 1) >= n + n; }
int main() {
#ifdef TEST
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	int L = 0, R = n;
	while (R - L > 1) {
		// cout << L << " " << R << endl;
		if (check(mid)) {
			R = mid;
		} else {
			L = mid;
		}
	}
	printf("%d\n", R);
	return 0;
}
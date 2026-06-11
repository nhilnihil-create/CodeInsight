#include <bits/stdc++.h>
#define ls (o << 1)
#define rs (o << 1 | 1)
#define mid ((L + R) >> 1)
using namespace std;
typedef long long LL;
const int N = 200500;
const int mod = 1e9 + 7;
int a[N];
int n, ans;
int main() {
#ifdef TEST
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i] -= i + 1;
	}
	for (int i = 0; i < n;) {
		if (a[i] == 0) {
			int cnt = 0;
			while (i < n && a[i] == 0) {
				cnt++;
				i++;
			}
			ans += (cnt + 1) / 2;
		} else {
			i++;
		}
	}
	cout << ans << endl;
	return 0;
}

# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn(1e5 + 5);

int n, a[maxn];
ll sum, cur, x, v[maxn];

int main() {
	int i;
	scanf("%d", &n);
	if (n == 1) return puts("YES"), 0;
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]), sum += a[i];
	cur = (ll)n * (n + 1) / 2;
	if (sum % cur) return puts("NO"), 0;
	sum /= cur, a[0] = a[n], cur = 0;
	for (i = 1; i <= n; ++i) {
		if ((a[i - 1] + sum - a[i]) % n) return puts("NO"), 0;
		x = (a[i - 1] + sum - a[i]) / n;
		if (x < 0) return puts("NO"), 0;
		cur += x;
	}
	if (cur != sum) return puts("NO"), 0;
    return puts("YES"), 0;
}
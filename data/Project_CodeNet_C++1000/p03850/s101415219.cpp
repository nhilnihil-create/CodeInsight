#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
int a[N], f[N], n;
long long s[N], ss[N];
int main() {
	scanf("%d", &n); scanf("%d", &a[1]); ss[1] = s[1] = a[1];
	for(int i = 2; i <= n; ++i) {
		char k; scanf("%c", &k);
		while (k != '+' && k != '-') scanf("%c", &k);
		f[i] = k == '-' ? -1 : 1;
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i] * f[i];
		ss[i] = ss[i - 1] + a[i];
	}
	int lst = -1; long long ans = LLONG_MIN;
	for(int i = n; i >= 1; --i) if(f[i] == -1) {
		ans = max (ans, s[i] - (s[n] - s[i]));
		if (lst > 0)
			ans = max (ans, s[i] - (s[lst] - s[i]) + ss[n] - ss[lst]);
		lst = i;
	}
	printf ("%lld\n", max (ans, s[n]));
	return 0;
}
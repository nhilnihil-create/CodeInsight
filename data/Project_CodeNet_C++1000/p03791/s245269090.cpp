#include <bits/stdc++.h>
#define LL long long
#define INF 0x7FFFFFFF//or 0x3f3f3f3f ? -Wall
using namespace std;

template<class T> inline
void read(T& x) {
	int f = 1; x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')   {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	x *= f;
}

/*============ Header Template ============*/

const int N = 100000 + 5;
const int mo = 1000000007;

int n;
int a[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	LL ans = 1; int d = 0;
	for (int i = 1; i <= n; i++) {
		d = max(d, i - 1 - (a[i - 1] + 1) / 2);
		ans = ans * (LL)(i - d) % mo;
	}
	printf("%lld\n", ans);
	return 0;
}
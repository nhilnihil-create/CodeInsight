#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];

template <class T> inline void in(T &x) {
	x = 0; int f = 1; char ch = getchar();
	for (; ch<'0' || ch>'9';) {if (ch=='-') f=-1; ch = getchar();}
	for (; ch>='0' && ch<='9';) x = x*10 + ch-'0', ch = getchar();
	x *= f;
}

int main() {
	int p, y; in(n);
	for (int i = 0; i < n; ++i) in(a[i]);
	sort(a + 0, a + n), reverse(a + 0, a + n);
	for (p = 0; p + 1< n && a[p + 1] > p + 1; ++p);
	for (y = 0; y < n && a[y] > p; ++ y);
	if ((a[p] - p)&1 && (y - p)&1) puts("Second");
	else puts("First");
	return 0;
}
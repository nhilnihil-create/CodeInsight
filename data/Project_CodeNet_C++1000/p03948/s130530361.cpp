#include<cstdio>
#include<iostream>
#define nc getchar
using namespace std;
inline void read(int &x) {
	char b = nc(); x = 0;
	for (; !isdigit(b); b = nc());
	for (; isdigit(b); b = nc()) x = x * 10 + b - '0';
}
int n, T, a[100005], mn, d, ans;
int main() {
	read(n); read(T);
	for (int i = 1; i <= n; ++i) read(a[i]);
	mn = a[1];
	for (int i = 2; i <= n; ++i) {
		mn = min(mn, a[i]);
		int t = a[i] - mn;
		if (t > d) d = t, ans = 1;
		else if (t == d) ++ans;
	} printf("%d\n", ans);
	return 0;
}
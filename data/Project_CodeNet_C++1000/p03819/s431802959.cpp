#include <bits/stdc++.h>
#define MAX_N 300000
#define MAX_M 100000
using namespace std;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, m, tr[MAX_M+5]; struct seg {int l, r;} s[MAX_N+5];
bool cmp(const seg &a, const seg &b) {return a.r-a.l < b.r-b.l;}
void inc(int p) {for (; p <= m; p += (p&-p)) tr[p]++;}
void dec(int p) {for (; p <= m; p += (p&-p)) tr[p]--;}
int sum(int p) {int ret = 0; for (; p; p -= (p&-p)) ret += tr[p]; return ret;}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(s[i].l), read(s[i].r);
	sort(s+1, s+n+1, cmp);
	for (int d = 1, p = 1; d <= m; d++) {
		while (p <= n && s[p].r-s[p].l < d)
			inc(s[p].l), dec(s[p].r+1), p++;
		int tot = 0;
		for (int i = d; i <= m; i += d)
			tot += sum(i);
		printf("%d\n", tot+n-p+1);
	}
	return 0;
}

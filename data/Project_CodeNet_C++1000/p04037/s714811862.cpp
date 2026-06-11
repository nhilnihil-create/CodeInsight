#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
char buf[1 << 23], *ps = buf, *pt = buf, pbuf[1 << 23], *pp = pbuf;
#define getchar() (ps == pt && (pt = (ps = buf) + fread(buf, 1, 1 << 23, stdin), ps == pt) ? EOF : *ps++)
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
int n, a[N];
void solve(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read();
	std :: sort(a + 1, a + 1 + n);
	std :: reverse(a + 1, a + 1 + n);
	a[n + 1] = 0;
	for (register int i = 1; i <= n; ++i)
		if (i >= a[i + 1]){
			int j = i + 1;
			while (j <= n && a[j] == i) ++j;
			--j;
			if ((j - i) & 1 || (a[i] - i) & 1) return puts("First"), void(0);
			else return puts("Second"), void(0);
		}
}
int main(){
	int T = 1;
	while (T--) solve();
}
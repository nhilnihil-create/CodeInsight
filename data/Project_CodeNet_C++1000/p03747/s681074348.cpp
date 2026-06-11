#include <bits/stdc++.h>
using namespace std;
inline char gc() {
	static char now[1<<16], *S, *T;
	if(S == T) {T = (S = now) + fread(now, 1, 1<<16, stdin); if(S == T) return EOF;}
	return *S++;
}
#define gc getchar
inline int read() {
	int x = 0, f = 1; char c = gc();
	while(c < '0' || c > '9') {(c ^ '-') ? 0 : (f = 0); c = gc();}
	while(c >= '0' && c <= '9') {x = (x << 3) + (x << 1) + (c ^ 48); c = gc();}
	return f ? x : ((~x) + 1);
}
#define N 100010
int n, L, T, x[N], d[N];
int main() {
	n = read(); L = read(); T = read();
	for (int i = 1; i <= n; ++ i) {
		x[i] = read(); d[i] = read();
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++ i) {
		if (d[i] == 2) d[i] = -1;
		x[i] += T * d[i];
		cnt += x[i] / L;
		if (x[i] % L < 0) -- cnt;
		x[i] = (x[i] % L + L) % L;
	}
	sort(x + 1, x + n + 1);
	cnt = (cnt % n + n) % n;
	for (int i = 1; i <= n; ++ i) printf("%d\n", x[(i + cnt - 1) % n + 1]);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define ge getchar()
#define Re read()

inline int read() {
	int x = 0, ch;
	while(!isdigit(ch = ge)) ;
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = ge;
	return x;
}

const int MAXN = 200000;

int n, N;
int a[MAXN + 1];
int v[MAXN + 1];
int x[MAXN + 1];

inline int chk() {
	int l = n, r = n, res = x[n]; x[0] = x[1], x[N + 1] = x[N];
	for(; l >= 1 && x[l] != x[l - 1] && x[r] != x[r + 1]; --l, ++r) res ^= 1;
	return res;
}

int main() {
	n = Re, N = (n << 1) - 1;
	for(int i = 1; i <= N; i++) v[i] = a[i] = Re;
	sort(v + 1, v + 1 + N); int l = 1, r = N, res = v[r];
	while(l <= r) {
		int mid = (l + r) >> 1, val = v[mid];
		for(int i = 1; i <= N; i++) x[i] = a[i] > val;
		if(!chk()) res = val, r = mid - 1;
		else l = mid + 1;
	} printf("%d\n", res);
	return 0;
}
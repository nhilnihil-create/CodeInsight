#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int M = 2e5+10;
ll ans=0;
int n, b[M];
struct psx{int Q, N;} a[M];

inline void init(){
	scanf("%d", &n);
	a[0].N = 1;
	a[n+1].Q = n;
	for(int i = 1, c; i <= n; i++) {
		scanf("%d", &c);
		a[i].Q = i-1;
		a[i].N = i+1;
		b[c] = i;
	}
}

inline void work(){
	for(int i = n; i >= 1; i--) {
		ans += 1LL * i * (b[i] - a[b[i]].Q) * (a[b[i]].N - b[i]);
		a[ a[b[i]].Q ].N = a[b[i]].N;
		a[ a[b[i]].N ].Q = a[b[i]].Q;
	}
}

inline void outo(){
	printf("%lld\n", ans);
}

int main() {
	init();
	work();
	outo();
	return 0;
}

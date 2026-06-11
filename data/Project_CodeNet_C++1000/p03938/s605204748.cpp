#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 10 ;
int p[maxn], a[maxn], b[maxn], pos[maxn] ;
int main() {
	int n ;
	scanf("%d", &n) ;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &p[i]) ;
		pos[p[i]] = i ;
	}
	a[1] = 1 ;
	for (int i = 2; i <= n; i ++) {
		if (pos[i] > pos[i - 1]) a[i] = a[i - 1] + pos[i] - pos[i - 1] + 1 ;
		else a[i] = a[i - 1] + 1 ;
	}
	b[n] = 1 ;
	for (int i = n - 1; i >= 1; i --) {
		if (pos[i] > pos[i + 1]) b[i] = b[i + 1] + pos[i] - pos[i + 1] + 1 ;
		else b[i] = b[i + 1] + 1 ;
	}
	for (int i = 1; i <= n; i ++) printf("%d ", a[i]) ;
	puts("") ;
	for (int i = 1; i <= n; i ++) printf("%d ", b[i]) ;
	puts("") ;
	return 0 ;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10 ;
int a[maxn], mx[20][maxn] ;
int query (int l, int r) {
	int k = log2 (r - l + 1) ;
	return max (mx[k][l], mx[k][r - (1 << k) + 1]) ;
}
int main() {
	int n, t ;
	scanf("%d%d", &n, &t) ;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]) ;
		mx[0][i] = a[i] ;
	}
	for (int i = 1; i < 20; i ++)
		for (int j = 1; j <= n - (1 << i) + 1; j ++)
			mx[i][j] = max (mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]) ;
	int mx_val = 0, cnt = 0 ;
	for (int i = 1; i < n; i ++) {
		int x = query (i + 1, n) ;
		if (x - a[i] >= mx_val) {
			if (x - a[i] == mx_val) cnt ++ ;
			else mx_val = x - a[i], cnt = 1 ;
		}
	}
	printf("%d\n", cnt) ;
	return 0 ;
}
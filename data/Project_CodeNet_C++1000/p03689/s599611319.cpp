//2018-1-17
//miaomiao
//
#include <bits/stdc++.h>
using namespace std;
 
#define For(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define N (500+5)

int mat[N][N];

int main(){
	int n, m, w, h;
	scanf("%d%d%d%d", &n, &m, &w, &h);
	
	For(i, 1, n) For(j, 1, m) mat[i][j] = 1000;

	long long tmp = 0;
	int tt = -1000*w*h+999;
	for(int i = w; i <= n; i += w)
	  for(int j = h; j <= m; j += h) mat[i][j] = tt, ++tmp;

	if((1ll*n*m*1000-tmp*1000) <= abs(tmp*tt)){
		puts("No"); return 0;
	}

	puts("Yes");
	For(i, 1, n) For(j, 1, m) printf("%d%c", mat[i][j], j==m? '\n': ' ');
	
	return 0;
}
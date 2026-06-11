//2017-11-4
//miaomiao
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define For(i, a, b) for(int i = (a); i <= (int)(b); ++i)

#define N (300+5)

int a[N][N];

int main(){
	int n;

	scanf("%d", &n);
	For(i, 1, n) For(j, 1, n) scanf("%d", &a[i][j]);
	
	bool flag;
	LL ans = 0;

	For(i, 1, n) For(j, i+1, n){
		if(i == j) continue;

		flag = true;
		For(k, 1, n) if(k != i && k != j){
			if(a[i][k] + a[k][j] < a[i][j]){puts("-1"); return 0;}
			else if(a[i][k] + a[k][j] == a[i][j]) flag = false;
		}
		ans += flag * a[i][j];
	}

	printf("%lld\n", ans);

	return 0;
}
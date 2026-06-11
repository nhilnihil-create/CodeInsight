//2018-1-20
//miaomiao
//
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define For(i, a, b) for(int i = (a); i <= (int)(b); ++i)

#define N (200+5)
const int A = 100;

int m, ans[N], l, r;

void Solve(LL n){
	if(n <= 1) return;

	if(n & 1){
		Solve(n-1);
		ans[--l] = ++m;
	}else{
		Solve(n>>1);
		ans[++r] = ++m;
	}
}

int main(){
	LL n;

	scanf("%lld", &n); ++n;

	l = A+1; r = A;
	Solve(n);
	
	printf("%d\n", m<<1);
	For(i, l, r) printf("%d ", ans[i]);
	For(i, 1, m) printf("%d%c", i, i==m? '\n': ' ');

	return 0;
}
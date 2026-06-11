#include <bits/stdc++.h>

#define For(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

const int N = 100010;

typedef long long LL;

void chkmax(LL &x, LL y){
	x = x > y ? x : y;
}

int n;
int op[N], A[N];
LL dp[N][3];

int main(){
	scanf("%d%d", &n, &A[1]);
	For(i, 2, n){
		char s[3];
		scanf("%s%d", s, &A[i]);
		op[i] = s[0] == '-';
	}

	For(i, 0, n) For(j, 0, 2) dp[i][j] = -(1ll << 60);
	dp[0][0] = 0;

	For(i, 1, n) For(j, 0, 2){
		LL val = dp[i - 1][j];
		For(k, 0, j)
			if(!op[i]) chkmax(dp[i][k], val + (k & 1 ? -A[i] : A[i]));
			else if(k != 2) chkmax(dp[i][k + 1], val + (k & 1 ? A[i] : -A[i]));
	}
	printf("%lld\n", max(dp[n][0], max(dp[n][1], dp[n][2])));
	
	return 0;
}
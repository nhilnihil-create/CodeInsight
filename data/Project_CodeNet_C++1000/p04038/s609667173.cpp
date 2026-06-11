#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 2010;
const int MOD = 1e9 + 7;

int dp[N][N], fak[N * N], inv[N * N];
int n, k;

inline int add(int A, int B){
	if(A + B >= MOD) return A + B - MOD;
	return A + B;
}

inline int mul(int A, int B){
	return (ll)A * B % MOD;
}

inline int pot(int A, int B){
	int ret = 1, bs = A;
	for(;B;B >>= 1){
		if(B & 1) ret = mul(ret, bs);
		bs = mul(bs, bs);
	}
	return ret;
}

void precompute(){
	fak[0] = 1, inv[0] = 1;
	for(int i = 1;i < N * N;i++){
		fak[i] = mul(fak[i - 1], i);
		inv[i] = pot(fak[i], MOD - 2);
	}
}

inline int ch(int n, int k){
	return mul(fak[n], mul(inv[k], inv[n - k]));
}


int f(int i,int j){
	if(j < i || i < 0) return 0;
	if(j == 0) return 1;
	if(dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = add(f(i - 1, j), mul(f(i, j - 1), ch((j - 1) * (k - 1) + k - 2 + i,k - 2)));
}

int main(){
	memset(dp, -1, sizeof(dp));
	precompute();
	scanf("%d%d", &n, &k);
	if(k == 1)
		printf("1\n");
	else
		printf("%d\n", mul(fak[n], f(n, n)));
}
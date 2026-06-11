#include <stdio.h>

const long long mod = 1000000007;
int N,K; long long D[2002][2002],inv[4004004]={0,1},fact[4004004]={1,1},ifact[4004004]={1,1};

long long comb(int n, int k)
{
	return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}

int main()
{
	scanf ("%d %d",&N,&K);
	if (K == 1){
		puts("1");
		return 0;
	}

	for (int i=2;i<N*K;i++){
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		fact[i] = fact[i-1] * i % mod;
		ifact[i] = ifact[i-1] * inv[i] % mod;
	}

	D[0][0] = 1;
	for (int i=0;i<=N;i++) for (int j=0;j<=i;j++){
		if (i + 1 <= N) D[i+1][j] = (D[i+1][j] + D[i][j]) % mod;
		if (j + 1 <= i) D[i][j+1] = (D[i][j+1] + D[i][j] * comb(N*K-i-j*(K-1)-1,K-2)) % mod;
	}

	printf ("%lld\n",D[N][N]*fact[N]%mod);

	return 0;
}
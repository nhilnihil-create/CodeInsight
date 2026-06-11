    //Created Time:2019年12月23日 星期一 15时39分53秒
    #include <iostream>
    #include <cstdio>
    #include <algorithm>
    #include <cstring>
    #define N 2005
    #define mod 1000000007
     
    using namespace std;
     
    int n, k;
    int f[N][N], fac[N * N], ifac[N * N], inv[N * N];
     
    int C(int ,int);
     
    int main(){
    	cin >> n >> k; fac[0] = ifac[0] = inv[1] = 1;
    	if (k == 1) { puts("1"); return 0;}
    	for (int i = 2; i <= n * k; ++i) inv[i] = mod - 1ll * mod / i * inv[mod % i] % mod;
    	for (int i = 1; i <= n * k; ++i) fac[i] = 1ll * fac[i - 1] * i % mod, ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
    	f[0][0] = 1; //f[i][j] 放了i个白色球和j种颜色球的方案
    	for (int i = 1; i <= n; ++i)
    		for (int j = 0; j <= i; ++j) {
    			f[i][j] = f[i - 1][j];
    			if(j) (f[i][j] += 1ll * C(n - i + (n - j + 1) * (k - 1) - 1, k - 2) * f[i][j - 1] % mod * (n - j + 1) % mod) %= mod;
    		}
    	cout << f[n][n] << endl;
    	return 0;
    }
     
    int C(int x, int y){
    	return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;
    }
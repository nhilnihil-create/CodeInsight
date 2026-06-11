#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e3 + 11;
const int MM = 5e6 + 11;
int n, k, f[N][N];
int fac[MM], inv[MM];
inline int M(int x, int y){
    return 1LL * x * y % mod;
}
inline int A(int x, int y){
    return x + y - (x + y >= mod ? mod : 0);
}
inline int C(int n, int m){
    if(n < m)return 0;
    return M(fac[n], M(inv[m], inv[n-m]));
}
int main(){
    fac[0] = fac[1] = inv[1] = inv[0] = 1;
    for(int i = 2;i <= 5e6; i++){
        fac[i] = M(fac[i-1], i);
        inv[i] = mod - M(mod / i, inv[mod%i]);
    }
    for(int i = 2;i <= 5e6; i++){
        inv[i] = M(inv[i], inv[i-1]);
    }
    cin>>n>>k;
    if(k == 1){
        puts("1");
        return 0;
    }
    for(int i = 1;i <= n; i++){
        f[i][0] = 1;
        for(int j = 1;j <= i; j++){
            f[i][j] = A(f[i-1][j], M(f[i][j-1], C(n * k - i - (k - 1) * (j - 1) - 1, k - 2)));
        }
    }
    printf("%d\n", M(f[n][n], fac[n]));
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int mod = 1e9 + 7;
const int N = 2e5 + 11;
int n, m, nn, mm;
LL fac[N], inv[N], a[N];
inline LL A(LL x, LL y){
    return x + y - (x + y >= mod ? mod : 0);
}
LL C(int n, int m){
    if(n < m)return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main(){
    cin>>n>>m>>nn>>mm;
    fac[0] = inv[0] = fac[1] = inv[1] = 1;
    for(int i = 2;i <= 2e5; i++){
        fac[i] = fac[i-1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod%i] % mod;
    }
    for(int i = 2;i <= 2e5; i++){
        inv[i] = inv[i] * inv[i-1] % mod;
    }
    a[1] = 1;
    for(int i = 2;i <= n - nn; i++){
        a[i] = C(i + mm - 1, mm);
    }
    for(int i = n - nn + 1;i <= n; i++)a[i] = a[i-1];
    LL ans = 0;
    for(int i = 2;i <= n; i++){
        ans = A(ans, a[i] * C(n - i + m - mm - 2, n - i) % mod);
    }
    for(int i = mm + 2;i <= m; i++){
        ans = A(ans, C(n - 2 + m - i, n - 2));
    }
    if(mm == m - 1)ans = a[n];
    cout<<ans<<endl;
    return 0;
}

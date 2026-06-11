#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <utility>
using namespace std;

#define LL long long
#define NFRAC 300000
const long long MOD = 1000000007;

LL fac[NFRAC+1];
LL ifac[NFRAC+1];

LL mpow(LL x, LL n){
    LL ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

LL comb(LL a, LL b){
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    LL tmp = ifac[a-b]* ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

LL perm(LL a, LL b){
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    return ifac[a-b] * fac[a] % MOD;
}

void init(){
    fac[0] = 1;
    ifac[0] = 1;
    for(LL i = 0; i<NFRAC+1; i++){
        fac[i+1] = fac[i]*(i+1) % MOD;
        ifac[i+1] = ifac[i]*mpow(i+1, MOD-2) % MOD;
    }
}

long long gcd(long long a, long long b) {
  long long _max = a > b ? a : b;
  long long _min = a > b ? b : a;
  if (!(_max%_min)) return _min;
  else return gcd(_min, _max%_min);
}
 
long long lcm(long long a, long long b) {
  return a/gcd(a,b)*b;
}

void solve(long long H, long long W, long long A, long long B){
    init();
    LL ans=0;
    for(LL i=0; i<H-A; i++){
        auto j = (i==H-A-1 ? 0 : 1);
        auto tmp = (comb(B+i, B)*comb(H+W-2-B-i-j, W-B-1-j))%MOD;
        ans = (ans + tmp)%MOD;
    }
    cout << ans << endl;
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(H, W, A, B);
    return 0;
}

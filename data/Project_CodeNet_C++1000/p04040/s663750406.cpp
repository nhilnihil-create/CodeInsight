#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;

//二項係数（nCk mod.p;1<=k<=n<=1e7,pは素数）
struct Combination{
    const int MOD = 1000000007;
    vector<ll> fac,finv,inv;
    Combination(const int MAX):fac(MAX),finv(MAX),inv(MAX){
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    long long comb(int n, int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
};

int main(){
    int H,W,A,B;
    cin >> H >> W >> A >> B;
    Combination com(200000);
    const int MOD = 1000000007;
    ll res = 0;
    for(int i=B;i<=W-1;i++){
        res+=com.comb(H-A-1+i,i)*com.comb(A-1+(W-i-1),A-1)%MOD;
        res%=MOD;
    }
    cout << res << endl;
    return 0;
}
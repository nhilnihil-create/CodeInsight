#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

using ll = long long;
using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

signed main() {
    int N, P;cin >> N >> P;
    map<int, int> mp;
    COMinit();
    for(int i = 0;i < N;i++){
        int a;cin >> a;
        mp[a % 2]++;
    }
    ll zero = 1;
    for(int i = 0;i < mp[0];i++)zero *= 2;
    if(P == 0){
        ll one = 0;
        for(int i = 0;i <= mp[1];i+=2){
            one += COM(mp[1], i);
        }
        if(mp[1] == 0)one = 1;
        cout<<zero * one<<endl;
    }else{
        ll one = 0;
        for(int i = 1;i <= mp[1];i+=2){
            one += COM(mp[1], i);
        }
        cout<<zero * one<<endl;
    }
}

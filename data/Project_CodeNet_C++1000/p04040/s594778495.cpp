#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> P;
#define REP(i, x, n) for(lint i = x ; i < n ; i++)
#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for(lint i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())

const int IINF = 1e9 + 10;
const lint LLINF = (lint)1e18 + 10;
const lint MOD = (lint)1e9 + 7;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

vector<lint> fact, inv;

lint power(lint x, lint n){
    lint res = 1;
    while(n > 0){
        if(n & 1){
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        n >>= 1;
    }
    return res;
}

lint comb(lint n, lint r){
    return fact[n] * ((inv[r] * inv[n-r]) % MOD) % MOD;
}

int main(){
    lint h, w, a, b;
    cin >> h >> w >> a >> b;
    lint siz = h + w + 5;
    fact.resize(siz);
    inv.resize(siz);
    fact[0] = 1;
    inv[0] = 1;
    REP(i, 1, siz){
        fact[i] = i * fact[i-1];
        fact[i] %= MOD;
        inv[i] = power(fact[i], MOD - 2);
    }
    lint ans = 0;
    REP(i, b, w){
        ans += comb(i+h-a-1, i) * comb(w-i-1+a-1, w-i-1);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
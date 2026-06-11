#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {
    int k,s; cin >> k >> s;
    ll ans = 0;
    rep(i,k+1){
        rep(j,k+1){
            if(s-i-j >= 0 && s-i-j <= k) ans ++;
        }
    }
    cout << ans;
    return 0;
}

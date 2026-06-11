#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll sz;
ll power(ll x, ll y){
    ll ret = 1;
    x %= MOD;
    while(y > 0){
        if(y & 1) {
            ret = (ret * x) % MOD;
        }
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ret;
}
ll modInverse(ll num){
    ll M = MOD;
    return power(num, M - 2);
}
ll fac[1000001];

ll arr[1000001];
map<pair<ll, ll>, ll> mapa;
ll nCr(ll n, ll r){
    if(r == 0)return 1;
    if(n < r)return 0;
    if(mapa.find(make_pair(n, r)) != mapa.end())return mapa[make_pair(n, r)];
    return mapa[make_pair(n, r)] = (fac[n] * modInverse(fac[r]) % MOD * modInverse(fac[n - r]) % MOD) % MOD;
}
ll idx[1000001];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
//    cout << nCr(10, 2);
    fac[0] = 1;
    for(ll i = 1; i <= 1000000; i ++){
        fac[i] = fac[i - 1] * i % MOD;
    }
    cin >> sz;
    sz ++;
    set<ll> st;
    memset(idx, -1, sizeof idx);
    ll tmp1, tmp2;
    for(int i = 0; i < sz; i ++){
        cin >> arr[i];
        if(idx[arr[i] - 1] == -1){
            idx[arr[i] - 1] = i;
        }
        else{
            tmp1 = idx[arr[i] - 1];
            tmp2 = i;
        }
        st.insert(arr[i]);
    }
//    cout << nCr(4, 4) << endl;
    cout << (int)st.size() << endl;
    
    for(ll i = 2; i <= sz; i ++){
        ll t =  nCr(sz, i) - nCr(tmp1 + (sz - tmp2 - 1), i - 1);
        if(t < 0)t += MOD;
        cout <<t << endl;
    }
    
//    cout << 1 << endl;
    return 0;
}

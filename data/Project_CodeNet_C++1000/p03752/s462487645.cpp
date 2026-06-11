#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define FOR(i, m, n) for(ll i = m; i < (n); i++)
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vll = vector<vl>;
using pll = pair<ll, ll>; 

ll N, K;
bool check(ll bit, vl &arr){
    ll seen = 1; //すでに見えているビルのbit列
    ll s = arr[0];
    FOR(i, 1, N){
        if(s < arr[i]){
            seen |= 1<<i;
            s = arr[i];
        }
    }
    if((bit & seen) == seen){
        return true;
    }
    return false; 
}

int main() {
    cin >> N >> K;
    vl a(N);
    rep(i, N){
        cin >> a[i];
    }

    ll ans = LONG_LONG_MAX;
    //見える建物をbit列で管理、1が見える建物
    rep(bit, 1<<N){
        if(__builtin_popcount(bit) >= K && check(bit, a)){
            ll tmp = 0;
            ll s = a[0];
            FOR(i, 1, N){
                if(bit & (1<<i)){
                    if(s < a[i]){
                        s = a[i];
                    }else{
                        s++;
                        tmp += s - a[i];
                    }
                }
            }
            ans = min(ans, tmp);
        }
    }

    cout << ans << endl;
}
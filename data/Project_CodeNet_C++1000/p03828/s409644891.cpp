#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

map<ll, ll> factorize(ll g){
    map<ll, ll> ret;
    if(g == 1){
        ret[1]++;
        return ret;
    }
    ll d = 2;
    while(d*d <= g){
        if(g % d == 0){
            ret[d]++;
            g /= d;
            while(g % d == 0){
                ret[d]++;
                g /= d;
            }
        }
        d++;
    }
    if(g != 1) ret[g]++;
    return ret;
}


int main(){
    ll N;
    cin >> N;

    map<ll, ll> cnt;
    rep(i, 2, N+1){
        auto t = factorize(i);
        for(auto p : t){
            cnt[p.first] += p.second;
        }
    }

    ll ans = 1;
    ll mod = 1e9+7;
    for(auto c : cnt){
        if(c.first == 1) continue;
        ans *= (c.second+1)%mod;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}
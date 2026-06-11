#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD = 1000000007;

void solve(long long N){
    map<ll, ll> mp;
    for(ll i = 2; i <= N; ++i){
        ll ii = i;
        for(ll j = 2; j <= ii; ++j){
            while(ii % j == 0){
                ii /= j;
                mp[j]++;
            }
        }
    }
    ll ans = 1;
    for(auto i : mp){
        ans = ((ans%MOD) * (i.second+1)%MOD) % MOD;
    }
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}

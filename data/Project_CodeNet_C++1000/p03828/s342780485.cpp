#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int MOD = 1000000007;

int main(void){
    int N; cin >> N;
    
    map<ll,ll> mp;
    for(ll i = 1; i <= N; i++){
        ll num = i;
        for(ll j = 2; j * j <= num; j++){
            if (num % j == 0){
                ll cnt = 0;
                while(num % j == 0){
                    num /= j;
                    cnt++;
                }
                mp[j] += cnt;
            }
        }
        if (num != 1) mp[num]++;
    }
    ll ans = 1;
    for(auto p: mp){
        // cout << p.first << ' ' << p.second << endl;
        ans *= (p.second + 1);
        ans %= MOD;
    }
    cout << ans << endl;
}

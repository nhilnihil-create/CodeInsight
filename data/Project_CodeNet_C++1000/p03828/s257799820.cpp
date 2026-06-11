#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
int main() {
    ll N; cin >> N;
    if(N==1){
        cout << 1 << endl;
        return 0;
    }

    map<ll, ll> m;
    for (int i = 2; i <= N; i++)
    {
        int icpy = i;
        for (int j = 2; j <= round(sqrt(N)); j++)
        {
            while(icpy%j==0){
                icpy /= j;
                m[j]++;
            } 
        }
        if(icpy!=1) m[icpy]++;
    }
    ll ans = 1;
    for(auto i: m){
        ans = ans * (i.second + 1) % mod;
    }
    cout << ans << endl;
}
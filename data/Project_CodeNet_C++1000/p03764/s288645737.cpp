#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e5 + 5, mod = 1e9 + 7;

ll add(ll a, ll b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (a + b) % mod;
}

ll mul(ll a, ll b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return 1ll * a * b % mod;
}

ll x[N], y[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int j = 0; j < m; j++) cin >> y[j];
    ll ans = 0, sum = 0;
    vector<int> v, v2;
    for(int i = 1; i < n; i++){
        ll disx = i, disx2 = n - i;
        ll kamx = mul(disx, disx2);
        kamx = mul(kamx, x[i] - x[i - 1]);
        v.push_back(kamx);
    }
    for(int j = 1; j < m; j++){
        ll disy = j, disy2 = m - j;
        ll kamy = mul(disy, disy2);
        kamy = mul(kamy, y[j] - y[j - 1]);
        sum = add(sum, kamy);
    }
    for(int i = 0; i < v.size(); i++){
        ans = add(ans, mul(v[i], sum));
    }
    cout << ans;


    return 0;

}


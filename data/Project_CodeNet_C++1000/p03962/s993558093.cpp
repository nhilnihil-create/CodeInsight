#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii ;
const int mod = 1e9 + 7;

ll binPow(ll x, ll y, ll md = mod){
    ll res = 1;
    x %= mod;
    while(y){
        if(y & 1){
            res = (res * x) % mod;
        }
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v(101);
    v[a]++;
    v[b]++;
    v[c]++;
    cout << 101 - count(v.begin(), v.end(), 0);
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}


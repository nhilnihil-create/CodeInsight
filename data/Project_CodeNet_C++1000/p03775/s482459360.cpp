#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2,62);

ll keta(ll x){
    ll digits = 0;
    while(x > 0){
        x /= 10;
        digits++;
    }
    return digits;
}

int main(){
    ll n;cin >> n;
    ll ans = keta(n);
    for(ll i = 1;i*i <= n;i++){
        if(n % i != 0){
            continue;
        }
        else{
            ll a = i;
            ll b = n / a;
            if(a > b){
                break;
            }
            ll f = max(keta(a),keta(b));
            ans = min(ans, f);
        }
    }
    cout << ans << endl;
}
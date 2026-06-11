#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, ans;

ll chk(ll a, ll b, ll c){
    ll mx = max({a, b, c});
    ll mn = min({a, b, c});
    return min(ans, mx-mn);
}

void f(){
    for(int i=0; i<=a/2+1; i++){
        ll x = b*i, y, z;
        ll l = 0, r = b/2+1;
        while(l+3 <= r){
            ll m1 = (l+l+r)/3, m2 = (l+r+r)/3;
            ll r1, r2;
            
            y = m1*(a-i); z = (b-m1)*(a-i);
            if(x && y && z) r1 = chk(x, y, z);
            else r1 = 1e18;
            
            y = m2*(a-i); z = (b-m2)*(a-i);
            if(x && y && z) r2 = chk(x, y, z);
            else r2 = 1e18;
            
            if(r1 < r2) r = m2 - 1;
            else l = m1 + 1;
        }
        for(ll j=l; j<=r; j++){
            y = j*(a-i); z = (b-j)*(a-i);
            if(x && y && z) ans = min(ans, chk(x, y, z));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;
    if(a%3 == 0 || b%3 == 0){ cout << 0; return 0; }
    ans = min(a, b);
    f();
    swap(a, b);
    f();
    cout << ans;
}

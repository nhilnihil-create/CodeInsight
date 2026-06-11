#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    
   
    ll absx = abs(x), absy = abs(y);
    ans = abs(absx - absy);
    if(x > y){
        if(x > y && x >= 0 && y <= 0) ans++;
        else ans += 2;
    }
    if(x < y && x < 0 && y > 0) ans++;
    if(ans == 0 && x != y) ans++;

    cout << ans << endl;
    return 0;
}
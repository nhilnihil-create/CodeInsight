#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll x, y;
    cin >> x >> y;
    ll a = abs(x), b = abs(y);
    ll ans = 0;
    if(a < b) {
        if(x < 0) ans++;
        ans += b-a;
        if(y < 0) ans++;
    }
    else if(a==b){
        if(x*y<0) ans++;
    }
    else{
        if(x > 0) ans++;
        ans+=abs(b-a);
        if(y > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
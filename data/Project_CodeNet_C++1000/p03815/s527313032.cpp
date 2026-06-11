#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    ll x; cin >> x;
    ll ans = 0;
    ll r = x%11;
    if(r==0);
    else if(r<=6) ans++;
    else ans += 2;
    ans += 2*(x/11);
    cout << ans;
}

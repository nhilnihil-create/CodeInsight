#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    ll x;
    scanf("%lld", &x);
    ll ans = x/11 * 2;
    ll t = x%11;
    if (t > 6) ans += 2;
    else if (t <= 6 && t > 0) ans++;
    cout << ans << endl;
    return 0;
}
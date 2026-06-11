#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const int oo = 1e9 + 7;
const int mod = 1e9 + 7, maxn = 200200;
const long double PI = acos(-1);

  

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x, y, ans = oo;

    cin >> x >> y;

    for (ll i=1; i<x; i++){
        ll ans1, ans2;
        ans1 = max(i*y, ((x-i-1)/2 + 1)*y) - min(i*y, ((x-i)/2)*y);
        ans2 = max(i*y, (x-i)*((y-1)/2 + 1)) - min(i*y, (x-i)*(y/2));
        ans = min(ans, min(ans1, ans2));
    }

    for (ll i=1; i<y; i++){
        ll ans1, ans2;
        ans1 = max(i*x, ((y-i-1)/2 + 1)*x) - min(i*x, ((y-i)/2)*x);
        ans2 = max(i*x, (y-i)*((x-1)/2 + 1)) - min(i*x, (y-i)*(x/2));
        ans = min(ans, min(ans1, ans2));
    }


    cout << ans << endl;
    return 0;
}
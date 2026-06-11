#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll func(ll n, ll x){
    if(n >= 0){
        return n / x + 1;
    } else {
        return 0;
    }
}

int main(void)
{
    ll a, b, x;
    cin >> a >> b >> x;

    ll ans = func(b, x) - func(a-1,x);
    cout << ans << endl;
    return 0;
}

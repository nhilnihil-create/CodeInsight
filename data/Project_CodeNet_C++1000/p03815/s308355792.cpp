#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll x; cin >> x;
    
    ll quotient = x / 11LL;
    ll mod = x % 11LL;

    ll ans = quotient * 2;
    
    if (6LL < mod) {
        ans += 2LL;
    }
    else if (mod == 0LL) {
    }
    else {
        ans += 1LL;
    }
    cout << ans << endl;

    return 0;
}
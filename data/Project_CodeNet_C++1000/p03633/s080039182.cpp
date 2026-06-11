#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

ll gcd_my(ll a, ll b) { return b ? gcd_my(b, a % b) : a; }

ll lcm_my(ll a, ll b) { return a / gcd_my(a, b) * b; }

int main() {
    ll n, ans=1;
    cin >> n;

    rep(i, n ) {
        ll tmp;
        cin >> tmp;
        ans = lcm_my(ans, tmp);
    }

    cout << ans << endl;


    return 0;
}
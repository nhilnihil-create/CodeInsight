#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;


int main() {
    ll n, ans=1;
    cin >> n;

    rep(i, n ) {
        ll tmp;
        cin >> tmp;
        ans = lcm(ans, tmp);
    }

    cout << ans << endl;


    return 0;
}
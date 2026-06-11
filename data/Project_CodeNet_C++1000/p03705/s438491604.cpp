#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    if (a > b){
        puts("0");
        return 0;
    }
    if (n == 1 && a != b){
        puts("0");
        return 0;
    }
    if (a == b){
        puts("1");
        return 0;
    }

    ll mi = a * (n-1) + b;
    ll ma = a + b*(n-1);
    ll ans = ma - mi +1;
    cout << ans << endl;


    return 0;
}

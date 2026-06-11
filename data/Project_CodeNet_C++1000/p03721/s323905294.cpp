#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll> x(100001, 0);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        x[a] += b;
    }
    ll sum = 0;
    rep(i, 100001) {
        sum += x[i];
        if(sum >= k) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

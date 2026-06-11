#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
// using ll = long long;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    map<ll, ll> d;
    rep(i, n) {
        ll a;
        cin >> a;
        ll b = a - 1;
        ll c = a + 1;
        if (d[a])
            d[a]++;
        else
            d[a] = 1;

        if (d[b])
            d[b]++;
        else
            d[b] = 1;

        if (d[c])
            d[c]++;
        else
            d[c] = 1;
    }

    ll maxVal = 0;
    for (auto const& x : d) {
        maxVal = max(x.second, maxVal); 
    }

    cout << maxVal << endl;
}
#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ldouble = long double;
 
const ll inf = 1ll << 60;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(s) cout << s;
#define println(s) cout << s << endl;
#define printd(s) cout << fixed << setprecision(10) << s << endl;

ll res = inf;

int main()
{
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        ll temp = a[x - 1];
        a[x - 1] = y;

        println(accumulate(all(a), 0ll));
        a[x - 1] = temp;
    }
}

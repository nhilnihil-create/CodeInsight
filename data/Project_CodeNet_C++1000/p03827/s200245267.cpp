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

ll res = 0;

int main()
{
    ll n;
    string s;
    cin >> n >> s;

    ll x = 0;
    for (char c: s)
    {
        if (c == 'I')
        {
            x++;
        }
        else
        {
            x--;
        }
        res = max(res, x);
    }

    println(res);
}

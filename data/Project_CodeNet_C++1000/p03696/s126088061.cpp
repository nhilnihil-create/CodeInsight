#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
typedef long long ll;
typedef vector<ll> vl;
#define rp(i, f, t) for (long long int i = f; i < t; i++)
#define pr(i, f, t) for (long long int i = t - 1; i >= f; i--)
#define ca(n, a) rp(ca_i, 0, n) cout << a[ca_i] << ((ca_i == n - 1) ? "\n" : " ")
#define za(n, a) rp(za_i, 0, n) a[za_i] = 0
#define be(a) a.begin(), a.end()
#define ce(a) cout << (a) << endl
int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ss[n];
    rp(i, 0, n)
    {
        if (s[i] == '(')
        {
            ss[i] = 1;
        }
        else
        {
            ss[i] = -1;
        }
    }
    rp(i, 0, n - 1) ss[i + 1] += ss[i];
    ll mi = inf;
    rp(i, 0, n) mi = min(mi, ss[i]);
    if (mi < 0)
    {
        rp(i, 0, -1 * mi)
        {
            cout << '(';
            ss[n - 1]++;
        }
    }
    cout << s;
    if (ss[n - 1] > 0)
    {
        rp(i, 0, ss[n - 1]) cout << ')';
    }
    cout << endl;
}
#include <stdio.h>
#include <bits/stdc++.h>
     
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
     
using namespace std;
 
const int N = 100000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

ll A = 11;

string f(ll x)
{
    string res;
    while (x)
    {
        res += (char)('0' + x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool ask(ll n)
{
    cout << "? " << n << endl;
    char c;
    cin >> c;
    return (c == 'Y');
    //return (n <= A && f(n) <= f(A)) || (n > A && f(n) > f(A));
}

void ans(ll n)
{
    cout << "! " << n << endl;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    //ll TL = 0.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    vector<ll> a = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    bool ok = true;
    int len = 0;
    rep(i, 1, 10)
    {
        bool res = ask(a[i]);
        if (!res)
        {
            ok = false;
            len = i;
            break;
        }
    }
    if (ok)
    {
        repb(i, 9, 0)
            if (!ask(a[i] - 1))
            {
                ans(a[i]);
                return 0;
            }
        ans(a[0]);
        return 0;
    }
    ll curr = 0;
    rep(p, 0, len - 1)
    {
        ll l = 0, r = 10, mid;
        while (r - l > 1)
        {
            mid = (l + r) / 2;
            if (ask(curr * 10 + mid))
                l = mid;
            else
                r = mid;
        }
        curr = curr * 10 + l;
    }
    ll l = -1, r = 9, mid;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        if (ask((curr * 10 + mid) * 10))
            r = mid;
        else
            l = mid;
    }
    curr = curr * 10 + r;
    ans(curr);
    return 0;
}
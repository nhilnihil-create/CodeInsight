#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define op(i) cout << (i) << endl;
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;

ll n, a, b;
ll h[100005];

bool check(ll x)
{
    ll res = 0;
    rep(i, n)
    {
        res += (max(0ll, h[i] - x * b) + (a - b - 1)) / (a - b);
    }
    return (res <= x);
}

int main()
{
    cin >> n >> a >> b;
    rep(i, n) cin >> h[i];
    ll MIN = 0, MAX = infi;
    while (1)
    {
        if (MIN + 1 == MAX)
            break;
        if (check((MIN + MAX) / 2))
        {
            MAX = (MIN + MAX) / 2;
        }
        else
        {
            MIN = (MIN + MAX) / 2;
        }
    }
    cout << MAX << endl;
}

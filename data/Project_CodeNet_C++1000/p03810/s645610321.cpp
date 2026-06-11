#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned ui;
typedef unsigned long long ul;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<int> vi;
#define pb push_back
#define fi first
#define se second
#define do(i, j, k) for(int i = j; i <= (k); i ++)
#define open(i, j, k) for(int i = j; i < (k); i ++)
#define dec(i, j, k) for(int i = j; i >= (k); i --)
#define mfil(x, k) memset(x, k, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
#define fio(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
template <class T> bool chkmin(T &x, T y)
{ return y < x ? (x = y, true) : false; }
template <class T> bool chkmax(T &x, T y)
{ return y > x ? (x = y, true) : false; }
struct __init { __init()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cout.precision(16); cout << fixed;
    srand(time(0) ^ ul(new char));
} } static __init__;
/* default code ends here */

bool solve(vi v)
{
    int tot = 0;
    bool flag = false;
    for(int x : v)
    {
        flag |= x == 1;
        tot += x - 1 & 1;
    }
    if(tot == 0)
        return false;
    if(tot & 1)
        return true;
    if(!flag && tot == v.size() - 1)
    {
        int g = 0;
        for(int x : v)
            g = __gcd(g, x / 2 * 2);
        open(i, 0, v.size())
            v[i] /= g;
        return !solve(v);
    }
    return false;
}

int main()
{
    int n;
    vi v;
    cin >> n;
    int x;
    do(i, 1, n)
    {
        cin >> x;
        v.pb(x);
    }
    cout << (solve(v) ? "First\n" : "Second\n");
    return 0;
}
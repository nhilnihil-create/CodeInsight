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

int n;
ll a, b, c, d;

void yes()
{
    cout << "YES\n";
    exit(0);
}
void no()
{
    cout << "NO\n";
    exit(0);
}

int main()
{
    cin >> n >> a >> b >> c >> d;
    n --;
    if(a < b)
        swap(a, b);
    a -= b;
    for(int i = n & 1; i <= n; i += 2)
    {
        if(a - i * c >= 0 && a - i * d <= 0)
            yes();
        if(min(abs(a - i * c), abs(a - i * d)) <= (d - c) * (n - i) / 2)
            yes();
    }
    no();
    return 0;
}
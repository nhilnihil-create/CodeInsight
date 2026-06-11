#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vec = vector<ll>;
using vect = vector<double>;
using Graph = vector<vector<ll>>;
#define loop(i, n) for (ll i = 0; i < n; i++)
#define Loop(i, m, n) for (ll i = m; i < n; i++)
#define pool(i, n) for (ll i = n; i >= 0; i--)
#define Pool(i, m, n) for (ll i = n; i >= m; i--)
#define mod 1000000007ll
//#define mod 998244353ll
#define flagcount __builtin_popcount
#define flag(x) (1ll << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1ll << i))
#define all(v) v.begin(), v.end()
#define low2way(v, x) lower_bound(all(v), x)
#define high2way(v, x) upper_bound(all(v), x)
#define idx_lower(v, x) (distance(v.begin(), low2way(v, x)))  //配列vでx未満の要素数を返す
#define idx_upper(v, x) (distance(v.begin(), high2way(v, x))) //配列vでx以下の要素数を返す
#define idx_lower2(v, x) (v.size() - idx_lower(v, x))         //配列vでx以上の要素数を返す
#define idx_upper2(v, x) (v.size() - idx_upper(v, x))         //配列vでxより大きい要素の数を返す
#define putout(a) cout << a << endl
#define Sum(v) accumulate(all(v), 0ll)
#define gcd(x, y) __gcd(x, y)
ll ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return -1;
}
template <typename T>
string make_string(T N)
{
    string ret;
    T now = N;
    while (now > 0)
    {
        T x = now % 10;
        ret += (char)('0' + x);
        now /= 10;
    }
    reverse(all(ret));
    return ret;
}
template <typename T>
T lcm(T x, T y)
{
    T z = gcd(x, y);
    return x * y / z;
}
template <typename T>
bool primejudge(T n)
{
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    double sqrtn = sqrt(n);
    for (T i = 3; i < sqrtn + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}
template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
//場合によって使い分ける
//const ll dx[4]={1,0,-1,0};
//const ll dy[4]={0,1,0,-1};
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//2次元配列の宣言
//vector<vector<ll>> field(h, vector<ll>(w));

int main()
{
    cout << fixed << setprecision(30);
    ll N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<ll> a(N), b(N), c(N);
    loop(i, N) cin >> a[i] >> b[i] >> c[i];
    map<ll, ll> C0, C1;
    for (ll i = -5000; i <= 5000; i++)
    {
        C0[i] = 1e9;
        C1[i] = 1e9;
    }
    ll X = N / 2, Y = N - X;
    //グループ0
    Loop(bit, 1, 1 << X)
    {
        ll A = 0, B = 0, cost = 0;
        loop(i, X) if (flagon(bit, i))
        {
            A += a[i];
            B += b[i];
            cost += c[i];
        }
        ll now = Mb * A - Ma * B;
        chmin(C0[now], cost);
    }
    //グループ1
    Loop(bit, 1, 1 << Y)
    {
        ll A = 0, B = 0, cost = 0;
        loop(i, Y) if (flagon(bit, i))
        {
            A += a[X + i];
            B += b[X + i];
            cost += c[X + i];
        }
        ll now = Mb * A - Ma * B;
        chmin(C1[now], cost);
    }
    ll ans = 1e9;
    chmin(ans, C0[0]);
    chmin(ans, C1[0]);
    for (ll i = -5000; i <= 5000; i++)
    {
        chmin(ans, C0[i] + C1[-i]);
    }
    if (ans == 1e9)
        putout(-1);
    else
        putout(ans);
    return 0;
}

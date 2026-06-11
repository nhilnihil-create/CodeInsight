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
//#define mod 1000000007ll
//#define mod 998244353ll
#define flagcount(bit) __builtin_popcount(bit)
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
T gcd(T a, T b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
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
    ll N, M;
    cin >> N >> M;
    vector<ll> X(N), num(100010), mod(M);
    vector<vector<ll>> S(M);
    vector<bool> seen(100010, false);
    loop(i, N)
    {
        cin >> X[i];
        num[X[i]]++;
        mod[X[i] % M]++;
        if (!seen[X[i]])
            S[X[i] % M].push_back(X[i]);
        seen[X[i]] = true;
    }
    ll ans = 0;
    ans += mod[0] / 2;
    loop(i, (M - 1) / 2)
    {
        ll x = 1 + i, y = M - 1 - i;
        //num[x]とnum[y]のグループをマッチさせる
        if (mod[x] < mod[y])
            swap(x, y);
        vector<ll> big = S[x], mini = S[y];
        ll SIZ = big.size(), siz = mini.size();
        //mod[x]-mod[y]<0にならない程度に、グループx内でペアをつくる
        ll safe = mod[x] - mod[y];
        loop(j, SIZ)
        {
            if (safe <= 1)
                break;
            while (num[big[j]] > 1)
            {
                if (safe <= 1)
                    break;
                num[big[j]] -= 2;
                safe -= 2;
                ans++;
            }
        }
        ans += mod[y];
    }
    if (M % 2 == 0)
        ans += mod[M / 2] / 2;
    putout(ans);
    return 0;
}

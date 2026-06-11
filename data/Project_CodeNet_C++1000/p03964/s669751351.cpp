#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll INF = 1e12;
const ll MOD = 1000000000 + 7;
#define PB push_back
#define PF push_front
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vpi vector<pii>
#define vll vector<ll>
#define vpl vector<pll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define mii map<int, int>
#define mci map<char, int>
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pr_d(x) cout << fixed << setprecision(15) << x << endl
#define ud(c, x) distance(c.begin(), upper_bound(all(c), x))
#define ld(c, x) distance(c.begin(), lower_bound(all(c), x))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define rep3(i, n) for (int i = (n - 1); i >= 0; --i)
#define rep4(i, a, b) for (int i = (a); i > (b); --i)
#define pb push_back
#define out(x) cout << x << "\n"
bool odd(int i)
{
    return i % 2;
}

#define all(v) v.begin(), v.end()
#define size(x) int(x.size())

int gcd(int a, int b)
{
    return __gcd(a, b);
}
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
void Yes_No(bool f)
{
    if (f)
        printf("Yes\n");
    else
        printf("No\n");
}
void YES_NO(bool f)
{
    if (f)
        printf("YES\n");
    else
        printf("NO\n");
}

template <typename T>
void deb1(T x)
{
    cout << "debug: " << x << "\n";
}

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
//-------------------ここから回答する-----------------------

ll g(ll a, ll b) //b以上の最小のaの倍数
{
    return --b / a * a + a;
}
pair<ll, ll> f(ll i, ll j, int a, int b)
{
    pair<ll, ll> p;
    if (a == b)
    {
        p.first = max(i, j);
        p.second = max(i, j);
        return p;
    }
    if (a > b)
    {
        pair<ll, ll> q;
        p.second = g(b, j);
        p.first = p.second / b * a;
        q.first = g(a, i);
        q.second = q.first / a * b;
        if (p.first >= i && p.second >= j)
            return p;
        else
            return q;
    }
    if (a < b)
    {
        pair<ll, ll> q;
        p.first = g(a, i);
        p.second = p.first / a * b;
        q.second = g(b, j);
        q.first = q.second / b * a;
        if (p.first >= i && p.second >= j)
            return p;
        else
            return q;
    }
    return p;
}

void solve(void)
{
    int n;
    cin >> n;
    vector<int> t(n), a(n);
    rep(i, n) cin >> t[i] >> a[i];
    ll taka = t[0];
    ll aok = a[0];
    // cout << endl;
    for (int i = 1; i < n; i++)
    {
        // cout << "before:" << taka << " " << aok << endl;
        // cout << "compare:" << t[i] << " " << a[i] << endl;
        pair<ll, ll> p = f(taka, aok, t[i], a[i]);
        taka = p.first;
        aok = p.second;
        // cout << "after:" << taka << " " << aok << endl
        //      << endl;
    }
    cout << taka + aok << endl;
}
int main(void)
{
    solve();
}

//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18);
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
//-std=gnu++17
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll n, k;
vector<ll> a, b;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    rep(i, n) cin >> a[i] >> b[i];
    ll ans = 0;
    vector<bool> bitk(31, false);
    rep(i, 31)
    {
        if ((1 << i) & k)
        {
            bitk[i] = true;
        }
    }
    rep(i, n)
    {
        bool check = true;
        rep(j, 31)
        {
            if (a[i] & (1 << j) && !bitk[j])
            {
                check = false;
            }
        }
        if (check)
            ans += b[i];
    }
    rep(i, 31)
    {
        if (!bitk[i])
            continue;
        ll sum = 0;
        rep(j, n)
        {
            if (a[j] & (1 << i))
                continue;
            bool check = true;
            for (int l = i + 1; l < 31; l++)
            {
                if (a[j] & (1 << l) && !bitk[l])
                {
                    check = false;
                }
            }
            if (check)
            {
                sum += b[j];
            }
        }
        chmax(ans, sum);
    }
    cout << ans << "\n";
}

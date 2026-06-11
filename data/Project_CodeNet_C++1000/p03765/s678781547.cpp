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
string s, t;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s >> t;
    vector<int> counts(s.size() + 1, 0), countt(t.size() + 1, 0);
    int counta = 0;
    int countb = 0;
    rep(i, s.size())
    {
        if (s[i] == 'A')
        {
            counta++;
        }
        else
        {
            countb++;
        }
        counts[i + 1] = countb - counta;
    }
    counta = 0;
    countb = 0;
    rep(i, t.size())
    {
        if (t[i] == 'A')
        {
            counta++;
        }
        else
        {
            countb++;
        }
        countt[i + 1] = countb - counta;
    }
    //debug(counts);
    //debug(countt);
    int q;
    cin >> q;
    vector<bool> ans(q);
    rep(i, q)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;
        int countss = counts[b] - counts[a];
        int counttt = countt[d] - countt[c];
        if ((countss - counttt) % 3 == 0)
        {
            ans[i] = true;
        }
        else
        {
            ans[i] = false;
        }
    }
    rep(i, q)
    {
        if (ans[i])
            YES;
        else
            NO;
    }
}
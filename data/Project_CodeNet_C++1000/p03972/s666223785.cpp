#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll w, h;
    cin >> w >> h;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < w; i++)
    {
        ll tmp;
        cin >> tmp;
        v.push_back(make_pair(tmp, 0));
    }
    for (ll i = 0; i < h; i++)
    {
        ll tmp;
        cin >> tmp;
        v.push_back(make_pair(tmp, 1));
    }
    sort(ALL(v));
    ll ans = 0;
    w++;
    h++;
    for (auto now : v)
    {
        if (now.second == 1)
        {
            ans += w * now.first;
            h--;
        }
        else
        {
            ans += h * now.first;
            w--;
        }
    }
    cout << ans << endl;
}
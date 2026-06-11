#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll h, w;
    cin >> h >> w;

    if (h * w % 3 == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    ll s = INF;
    for (int i = 0; i <= h; i++)
    {
        ll a = i * w;
        ll b = (h - i) * (w / 2);
        ll c = h * w - (a + b);
        s = min(s, max({a, b, c}) - min({a, b, c}));
        a = i * w;
        b = ((h - i) / 2) * w;
        c = h * w - (a + b);
        s = min(s, max({a, b, c}) - min({a, b, c}));
    }
    swap(h, w);
    for (int i = 0; i <= h; i++)
    {
        ll a = i * w;
        ll b = (h - i) * (w / 2);
        ll c = h * w - (a + b);
        s = min(s, max({a, b, c}) - min({a, b, c}));
        a = i * w;
        b = ((h - i) / 2) * w;
        c = h * w - (a + b);
        s = min(s, max({a, b, c}) - min({a, b, c}));
    }
    cout << s << endl;
}

//書き方の工夫
//↑によって記述量かなり減らせる

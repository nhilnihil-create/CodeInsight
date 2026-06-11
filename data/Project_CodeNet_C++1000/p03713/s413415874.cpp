#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
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
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
int main()
{
    ll H, W;
    cin >> H >> W;
    ll ans = INF, S = H * W;
    rep(h, H)
    {
        ll s1 = h * W, s2 = (H - h) * (W / 2), s3 = S - (s1 + s2);
        ll sm = min({s1, s2, s3}), sM = max({s1, s2, s3});
        chmin(ans, sM - sm);
    }
    rep(w, W)
    {
        ll s1 = H * w, s2 = (H / 2) * (W - w), s3 = S - (s1 + s2);
        ll sm = min({s1, s2, s3}), sM = max({s1, s2, s3});
        chmin(ans, sM - sm);
    }
    rep(h, H)
    {
        ll s1 = h * W, s2 = ((H - h) / 2) * W, s3 = S - (s1 + s2);
        ll sm = min({s1, s2, s3}), sM = max({s1, s2, s3});
        chmin(ans, sM - sm);
    }
    rep(w, W)
    {
        ll s1 = H * w, s2 = H * ((W - w) / 2), s3 = S - (s1 + s2);
        ll sm = min({s1, s2, s3}), sM = max({s1, s2, s3});
        chmin(ans, sM - sm);
    }
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    ll H, W;
    cin >> H >> W;
    ll s1, s2, s3, s4, s5, s6;

    // s1
    ll a1, b1;
    a1 = H / 3;
    b1 = (H - a1 + 1) / 2;
    s1 = (abs(b1 - a1) * W);

    // s2
    ll a2, b2;
    a2 = W / 3;
    b2 = (W - a2 + 1) / 2;
    s2 = (abs(b2 - a2) * H);

    // s3
    ll a3, b3, c3;
    a3 = (H + 2) / 3;
    b3 = (H - a3) * (W / 2);
    c3 = (W * H) - (a3 * W) - b3;
    a3 *= W;
    s3 = max(max(abs(a3 - b3), abs(b3 - c3)), abs(c3 - a3));

    // s4
    ll a4, b4, c4;
    a4 = (W + 2) / 3;
    b4 = (W - a4) * (H / 2);
    c4 = (W * H) - (a4 * H) - b4;
    a4 *= H;
    s4 = max(max(abs(a4 - b4), abs(b4 - c4)), abs(c4 - a4));

    // s5
    ll a5, b5, c5;
    a5 = H / 3;
    b5 = (H - a5) * (W / 2);
    c5 = (W * H) - (a5 * W) - b5;
    a5 *= W;
    s5 = max(max(abs(a5 - b5), abs(b5 - c5)), abs(c5 - a5));

    // s6
    ll a6, b6, c6;
    a6 = W / 3;
    b6 = (W - a6) * (H / 2);
    c6 = (W * H) - (a6 * H) - b6;
    a6 *= H;
    s6 = max(max(abs(a6 - b6), abs(b6 - c6)), abs(c6 - a6));

    // cout << s1 << ':' << s2 << ':' << s3 << ':' << s4 << ':' << s5 << ':' << s6 << endl;
    ll ans = min(min(min(s1, s2), min(s3, s4)), min(s5, s6));
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}

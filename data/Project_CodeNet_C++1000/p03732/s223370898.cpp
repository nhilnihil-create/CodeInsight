#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

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

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

ll N, W;
ll w1, v1;
// vw1[i]: weightがw1+iである品物のvalueのvector
vector<ll> vw1[10];

int main()
{
    cin >> N >> W;
    cin >> w1 >> v1;
    vw1[0].push_back(v1);

    for (int i = 0; i < N - 1; i++)
    {
        ll w, v;
        cin >> w >> v;
        for (int j = 0; j <= 3; j++)
        {
            if (w == w1 + j)
            {
                vw1[j].push_back(v);
            }
        }
    }

    // w1〜w1+3の各weightごとに価値が高い順にsort
    for (int j = 0; j <= 3; j++)
    {
        sort(vw1[j].begin(), vw1[j].end(), greater<ll>());
    }

    ll ans = 0, sum = 0;
    // weightが
    // w1のものをi個、
    // w1+1のものをj個、
    // w1+2のものをk個、
    // w1+3のものをl個
    // 取った場合を全探索してmaxをとる
    for (int i = 0; i <= vw1[0].size() && w1 * i <= W; i++)
    {
        for (int j = 0; j <= vw1[1].size() && w1 * i + (w1 + 1) * j <= W; j++)
        {
            for (int k = 0; k <= vw1[2].size() && w1 * i + (w1 + 1) * j + (w1 + 2) * k <= W; k++)
            {
                sum = 0;
                sum += accumulate(vw1[0].begin(), vw1[0].begin() + i, 0LL);
                sum += accumulate(vw1[1].begin(), vw1[1].begin() + j, 0LL);
                sum += accumulate(vw1[2].begin(), vw1[2].begin() + k, 0LL);

                ll rest_w = W - w1 * i - (w1 + 1) * j - (w1 + 2) * k;
                ll l = min(ll(vw1[3].size()), rest_w / (w1 + 3));
                sum += accumulate(vw1[3].begin(), vw1[3].begin() + l, 0LL);
                ans = max(ans, sum);
            }
        }
    }

    cout << ans << endl;
}
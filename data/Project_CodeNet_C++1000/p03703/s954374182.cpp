#include "bits/stdc++.h"

using namespace std;

template <typename T>
struct BIT
{
    int N, K;
    vector<T> bit;

    BIT(int X)
    {
        bit = vector<T>(X + 1, 0);
        N = X + 1;
        K = pow(2, (int)(log(X) / log(2)));
    }

    void add(int idx, T w)
    {
        for (int x = idx; x <= N; x += x & -x)
        {
            bit[x] += w;
        }
    }

    T sum(int idx)
    {
        T res = 0;
        for (int x = idx; x > 0; x -= x & -x)
            res += bit[x];
        return res;
    }
};

void solve()
{
    long n, k;
    cin >> n >> k;
    vector<long> as(n), bs(n + 1);
    set<long> s;
    s.insert(0);
    for (int i = 0; i < n; i++)
    {
        cin >> as[i];
        as[i] -= k;
        bs[i + 1] = bs[i] + as[i];
        s.insert(bs[i + 1]);
    }
    int cnt = 1;
    map<long, int> mp;
    for (long x : s)
    {
        mp[x] = cnt++;
        //cout << x << ' ' << mp[x] << endl;
    }
    for (int i = 0; i <= n; i++)
    {
        bs[i] = mp[bs[i]];
    }
    BIT<long> bit(cnt + 1);
    long ans = 0;
    for (int r = 0; r <= n; r++)
    {
        ans += bit.sum(bs[r]);
        bit.add(bs[r], 1);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}

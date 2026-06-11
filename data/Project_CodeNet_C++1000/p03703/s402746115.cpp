#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

template <typename T>
struct BIT
{
    int n;
    vector<T> bit;
    //1-indexed
    BIT() : n(-1) {}
    BIT(int n_, T d) : n(n_), bit(n_ + 1, d) {}

    T sum(int i)
    {
        T s = bit[0];
        for (int x = i; x > 0; x -= (x & -x))
            s += bit[x];
        return s;
    }
    void add(int i, T a)
    {
        if (i == 0)
            return;
        for (int x = i; x <= n; x += (x & -x))
            bit[x] += a;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int sum = 0;
    vector<P> v;
    v.push_back(P(sum, 1));
    rep(i, n)
    {
        int a;
        cin >> a;
        a -= k;
        sum += a;
        v.push_back(P(sum, i + 2));
    }
    sort(all(v));
    int ans = 0;
    BIT<int> bit(n + 2, 0);
    rep(i, n + 1)
    {
        int p = v[i].second;
        ans += bit.sum(p);
        bit.add(p, 1);
    }
    cout << ans << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
template <typename Mnd>
struct segment_tree
{
    int sz;
    vector<Mnd> data;
    function<Mnd(Mnd, Mnd)> f;
    Mnd e;
    //サイズだけ指定して初期化
    segment_tree(int _sz, function<Mnd(Mnd, Mnd)> _f, Mnd _e) : f(_f), e(_e)
    {
        sz = 1;
        while (sz < _sz)
            sz <<= 1;
        data.assign(sz * 2, e);
    }
    //参照渡しなので代入とかもできる
    Mnd &operator[](const int &k)
    {
        return data[k + sz];
    }
    //木を構築 O(n)
    void build()
    {
        for (int i = sz - 1; i > 0; i--)
            data[i] = f(data[2 * i], data[2 * i + 1]);
    }
    //更新しつつ木を再構築 O(log n)
    void update(int k, Mnd x)
    {
        data[k += sz] = x;
        while (k >>= 1)
            data[k] = f(data[2 * k], data[2 * k + 1]);
    }
    //[a,b)でのクエリに答える　O(log n)
    Mnd query(int a, int b) const
    {
        Mnd l = e, r = e;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
        {
            if (a & 1)
                l = f(l, data[a++]);
            if (b & 1)
                r = f(r, data[--b]);
        }
        return f(l, r);
    }
};
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> r(n + 1, 0), p(n + 1, 0);
    for (size_t i = 0; i < n; i++)
    {
        r[i + 1] = r[i] + a[i];
        p[i + 1] = r[i + 1] - (i + 1) * k; //転倒数(i番目以下でp[i]より小さい要素の数)を求めたい数列
    }
    //座標圧縮,重複要素があることに注意
    vector<ll> b = p;
    map<ll, int> mp;
    sort(all(b));
    for (int i = 0; i < n + 1; i++)
    {
        if (mp.find(b[i]) == mp.end())
            mp[b[i]] = i;
    }
    //セグ木にぶち込む
    ll ans = 0;
    segment_tree<int> seg(n + 10, [](int a, int b) { return a + b; }, 0);
    seg.build();
    for (int i = 0; i < n + 1; i++)
    {
        ans += seg.query(0, mp[p[i]] + 1); //i番目以下でp[i]より小さい要素の数
        seg.update(mp[p[i]], seg[mp[p[i]]] + 1);
    }

    cout << ans << endl;
}
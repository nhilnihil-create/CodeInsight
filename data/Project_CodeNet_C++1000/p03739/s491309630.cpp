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
template <typename Set>
struct Monoid
{
    using Op = function<Set(Set, Set)>;
    const Op f;
    const Set e;
    Monoid(const Op F, const Set E) : f(F), e(E)
    {
    }
};
template <typename Set>
struct SegmentTree
{
    using Op = function<Set(Set, Set)>;
    Monoid<Set> M;
    Set e;
    int size; //一番下以外の区間たち全部の数
    vector<Set> seg;
    SegmentTree(int n, const Monoid<Set> &M) : M(M)
    {
        size = 1;
        while (size < n)
        {
            size <<= 1;
        }
        e = M.e;
        seg.assign(2 * size, e);
    }
    void set(int k, const Set &x)
    {
        seg[k + size] = x;
    }
    void build()
    {
        for (int k = size - 1; k > 0; k--)
        {
            seg[k] = M.f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }
    void update(int k, const Set &x)
    {
        k += size;
        seg[k] = x;
        while (k >>= 1)
        {
            seg[k] = M.f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }
    Set query(int a, int b) //区間[a,b)に対して演算したやつを返す
    {
        Set L = e, R = e;
        for (a += size, b += size; a < b; a >>= 1, b >>= 1) //ループ一回ごとにa,bは親に向かう
        {
            if (a & 1) //a%2==1なら
            {
                L = M.f(L, seg[a++]);
            }
            if (b & 1)
            {
                R = M.f(seg[--b], R);
            }
        }
        return M.f(L, R);
    }
};
int main()
{
    ll n;
    cin >> n;
    vint a(n), s(n + 1);
    Monoid<ll> M([](ll a, ll b) { return a + b; }, 0);
    SegmentTree<ll> sg(n, M), sg2(n, M);
    rep(i, n)
    {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
        sg.update(i, a[i]);
        sg2.update(i, a[i]);
    }
    ll prev = 1, ans = 0;
    rep(i, n)
    {
        ll sum = sg.query(0, i + 1);
        if (sum == 0)
        {
            if (prev < 0)
            {
                sg.update(i, sg.query(i, i + 1) + 1);
            }
            else
            {
                sg.update(i, sg.query(i, i + 1) - 1);
            }
            if (prev != 0)
                prev *= -1;
            else
                prev = 1;
            ans++;
            continue;
        }
        else
        {
            ll sgn = sum / abs(sum);
            if (prev == sgn)
            {
                ll cnt = -sgn - sum;
                ans += abs(cnt);
                sg.update(i, sg.query(i, i + 1) + cnt);
            }
            prev *= -1;
        }
    }
    prev = -1;
    ll ans2 = 0;
    rep(i, n)
    {
        ll sum = sg2.query(0, i + 1);
        if (sum == 0)
        {
            if (prev < 0)
            {
                sg2.update(i, sg2.query(i, i + 1) + 1);
            }
            else
            {
                sg2.update(i, sg2.query(i, i + 1) - 1);
            }
            if (prev != 0)
                prev *= -1;
            else
                prev = 1;
            ans2++;
            continue;
        }
        else
        {
            ll sgn = sum / abs(sum);
            if (prev == sgn)
            {
                ll cnt = -sgn - sum;
                ans2 += abs(cnt);
                sg2.update(i, sg2.query(i, i + 1) + cnt);
            }
            prev *= -1;
        }
    }
    cout << min(ans, ans2);
    return 0;
}
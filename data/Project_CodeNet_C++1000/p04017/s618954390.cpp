#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using VS = vector<string>;
using VB = vector<bool>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;
using TI3 = std::tuple<int, int, int>;
using TI4 = std::tuple<int, int, int, int>;
using TL3 = std::tuple<ll, ll, ll>;
using TL4 = std::tuple<ll, ll, ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, s, n, d) for (int i = (s); i < (int)(n); i += (d))
#define allpt(v) (v).begin(), (v).end()
#define allpt_c(v) (v).cbegin(), (v).cend()
#define allpt_r(v) (v).rbegin(), (v).rend()

const int mod1 = 1e9 + 7, mod2 = 998244353, mod3 = 1e9 + 9;
const int mod = mod2;
const ll inf = 1e18;

const string wsp = " ";
const string tb = "\t";
const string rt = "\n";

template <typename T>
void show1dvec(const vector<T> &v)
{
    if (v.size() == 0)
        return;
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;

    return;
}

template <typename T>
void show2dvec(const vector<vector<T>> &v)
{
    int n = v.size();
    rep(i, n) show1dvec(v[i]);
}

template <typename T, typename S>
void show1dpair(const vector<pair<T, S>> &v)
{
    int n = v.size();
    rep(i, n) cout << v[i].first << wsp << v[i].second << rt;
    return;
}

template <typename T, typename S>
void pairzip(const vector<pair<T, S>> &v, vector<T> &t, vector<T> &s)
{
    int n = v.size();
    rep(i, n)
    {
        t.push_back(v[i].first);
        s.push_back(v[i].second);
    }
    return;
}

template <typename T>
void maxvec(vector<T> &v)
{
    T s = v[0];
    int n = v.size();
    rep(i, n - 1)
    {
        if (s > v[i + 1])
        {
            v[i + 1] = s;
        }
        s = v[i + 1];
    }
}

template <typename T, typename S>
bool myfind(T t, S s)
{
    return find(t.cbegin(), t.cend(), s) != t.cend();
}

bool check(int y, int x, int h, int w)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}

template <typename T>
vector<T> cumsum(const vector<T> &v)
{
    T s = 0;
    vector<T> ret;

    rep(i, v.size())
    {
        s += v[i];
        s %= mod;
        ret.emplace_back(s);
    }
    return ret;
}

bool iskadomatsu(int a, int b, int c)
{
    return (a != b && b != c && c != a) && ((a > b && b < c) || (a < b && b > c));
}

VS split(string s, char c)
{
    VS ret;
    string part;
    s += c;
    rep(i, s.length())
    {
        if (s[i] == c)
        {
            ret.emplace_back(part);
            part = "";
        }
        else if (s[i] != c)
        {
            part += s[i];
        }
    }
    return ret;
}

string removezero(string &s)
{
    string ret;
    for (auto z : s)
        if (z != '0')
            ret += z;
    return ret;
}

ll sumdigit(ll x)
{
    ll ans{0};
    while (x > 0)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

template <typename T, typename S, typename R>
ll pow_mod(T p, S q, R mod = 1ll)
{
    ll ret = 1, r = p;
    while (q)
    {
        if (q % 2)
            ret *= r, ret %= mod;
        r = (r * r) % mod, q /= 2;
    }
    return ret % mod;
}

template <typename T, typename S>
ll pow_no_mod(T p, S q)
{
    ll ret = 1, r = p;
    while (q)
    {
        if (q % 2)
            ret *= r;
        r = (r * r), q /= 2;
    }
    return ret;
}

void make_frac_tables(VL &frac_list, VL &frac_inv_list)
{
    rep(i, frac_list.size() - 1)
    {
        frac_list[i + 1] *= frac_list[i] * (i + 1);
        frac_list[i + 1] %= mod;
        frac_inv_list[i + 1] *= frac_inv_list[i] * pow_mod(i + 1, mod - 2, mod);
        frac_inv_list[i + 1] %= mod;
    }
}

ll comb(int a, int b, const VL &frac_list, const VL &frac_inv_list)
{
    if (a < b)
        return 0;
    if (b < 0)
        return 0;
    ll ret = frac_list[a];
    ret *= frac_inv_list[b];
    ret %= mod;
    ret *= frac_inv_list[a - b];
    ret %= mod;
    return ret;
}



int main()
{

    cin.tie(0);
    ios::sync_with_stdio(false);

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    const int m = 40;
    int n, q, l, a, b, p, ans;
    cin >> n;
    VL x_list(n);
    VVI doubling(n, VI(m, n));
    rep(i, n) cin >> x_list[i];
    cin >> l;
    rep(i, n - 1)
    {
        p = lower_bound(allpt_c(x_list), x_list[i] + l) - x_list.cbegin();
        doubling[i][0] = x_list[p] == x_list[i] + l ? p : p - 1;
    }

    rep(j, m - 1) rep(i, n - 1)
    {
        if (doubling[i][j] < n && doubling[doubling[i][j]][j] < n)
            doubling[i][j + 1] = doubling[doubling[i][j]][j];
    }

    cin >> q;
    rep(i, q)
    {
        cin >> a >> b;
        --a, --b;
        ans = 0;
        if (a > b)
        {
            swap(a, b);
        }

        while (a != b)
        {
            if (doubling[a][0] > b)
            {
                ans++;
                break;
            }
            rep(j, m - 1)
            {
                if (doubling[a][j + 1] > b)
                {
                    ans += pow(2, j);
                    a = doubling[a][j];
                    break;
                }
            }
        }
        cout << ans << rt;
    }



    return 0;
}

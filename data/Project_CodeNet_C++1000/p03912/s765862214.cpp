#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define allpt(v) (v).begin(), (v).end()
#define allpt_r(v) (v).rbegin(), (v).rend()


const int mod = 1e9 + 7;
const string wsp = " ";
const string tb = "\t";
const string rt = "\n";

template <typename T>
void show1dvec(vector<T> v)
{
    if (v.size() == 0)
        return;
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;
    return;
}

template <typename T>
void show2dvec(vector<vector<T>> v)
{
    int n = v.size();
    rep(i, n) show1dvec(v[i]);
}

class Unionfind
{
    vector<int> p;

public:
    int find(int x);
    void unite(int x, int y);
    Unionfind(int n);
};

Unionfind::Unionfind(int n)
{
    for (int i = 0; i < n; i++)
    {
        p.push_back(i);
    }
}
int Unionfind::find(int x)
{
    while (p[x] != x)
    {
        p[x] = p[p[x]];
        x = p[x];
    }
    return x;
}

void Unionfind::unite(int x, int y)
{
    x = Unionfind::find(x);
    y = Unionfind::find(y);
    if (x != y)
    {
        p[x] = y;
    }
}

void getpair(int &ans, const int m, vector<int> &v)
{
    int a;
    rep(i, m)
    {
        if (i == 0)
        {
            ans += v[i] / 2;
            v[i] = v[i] % 2;
        }
        else if (m % 2 == 0 && i == m / 2)
        {
            ans += v[i] / 2;
            v[i] = v[i] % 2;
        }
        else
        {
            a = min(v[i], v[m - i]);
            ans += a;
            v[i] -= a;
            v[m - i] -= a;
        }
    }
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, m, x, y, ans = 0;
    const int xmax = 100001;
    cin >> n >> m;
    VI histgram(xmax, 0), modhist(m, 0);
    rep(i, n)
    {
        cin >> x;
        histgram[x]++;
    }
    rep(i, xmax)
    {
        if (histgram[i] == 1)
        {
            histgram[i] = 0;
            modhist[i % m]++;
        }
        else if (i % m == 0)
        {
            modhist[i % m] += histgram[i];
            histgram[i] = 0;
        }
        else if (i % m == m / 2 && m % 2 == 0)
        {
            modhist[i % m] += histgram[i];
            histgram[i] = 0;
        }
        else if (histgram[i] % 2 == 1)
        {
            histgram[i]--;
            modhist[i % m]++;
        }
    }

    getpair(ans, m, modhist);

    rep(i, xmax)
    {
        if (modhist[m - (i % m)] > 0)
        {
            y = min(modhist[m - (i % m)], histgram[i]);
            histgram[i] -= y;
            modhist[m - (i % m)] -= y;
            ans += y;
        }
    }
    rep(i, xmax)
    {
        ans += histgram[i] / 2;
        histgram[i] -= (histgram[i] / 2) * 2;
    }
    cout << ans << rt;

    return 0;
}

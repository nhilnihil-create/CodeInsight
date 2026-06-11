#pragma GCC optimize("Ofast,fast-math,unroll-loops")
 
#include <bits/stdc++.h>
 
#define int ll
//#define double long double
#define endl '\n'
#define all(C) (C).begin(), (C).end()
#define rall(C) (C).rbegin(), (C).rend()
#define mp make_pair 
#define pb emplace_back
#define dbg(x) cerr << #x << " : " << x << endl
//#define PI 3.141592653589
 
using namespace std;
        
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair <int, int>;
using pld = pair <ld, ld>;

/*
const ll MAX_MEM = 4e8;
char MEM[MAX_MEM];
ll MEM_POS = 0;
void* operator new(size_t x)
{
    auto ret = MEM + MEM_POS;
    MEM_POS += x;
    assert(MEM_POS < MAX_MEM);
    return ret;
}
void operator delete(void*)
{}
*/
        
template <class T>
istream& operator>> (istream &in, vector <T> &a)
{
    for (auto &i : a)
        in >> i;
    return in;
}
        
template <class T> 
ostream& operator<< (ostream &out, vector <T> a)
{
    for (auto &i : a)
        out << i << ' ';
    return out;
}
        
template <class T, class U>
istream& operator>> (istream &in, pair <T, U> &p)
{
    in >> p.first >> p.second;
    return in;
}
        
template <class T, class U>
ostream& operator<< (ostream &out, pair <T, U> p)
{
    out << p.first << " " << p.second << " ";
    return out;
}
        
inline void Start()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen("lol.in", "r", stdin);
    //freopen("lol.out", "w", stdout);
}

vector <vector <int>> g;
vector <int> p, h;
void dfs(int v)
{
    for (auto &to : g[v])
    {
        h[to] = h[v] + 1;
        dfs(to);
    }
}

signed main()
{
    Start();
    int n, k;
    cin >> n >> k;
    g.resize(n);
    p.resize(n);
    h.resize(n);
    cin >> p;
    for (auto &i : p)
        --i;
    int ans = 0;
    if (p[0] != 0)
        p[0] = 0, ++ans;
    for (int i = 1; i < n; ++i)
        g[p[i]].pb(i);
    dfs(0);
    set <pii> st;
    for (int i = 0; i < n; ++i)
        st.emplace(-h[i], i);
    function<void(int)> ers = [&] (int v)
    {
        st.erase(mp(-h[v], v));
        for (auto &to : g[v])
        {
            if (st.count(mp(-h[to], to)))
                ers(to);
        }
    };
    while (true)
    {
        if (st.empty())
            break;
        int dpth = st.begin()->first * -1;
        if (dpth <= k)
            break;
        int v = st.begin()->second;
        for (int i = 0; i < k - 1 && p[v] != 0; ++i, v = p[v]);
        ++ans;
        ers(v);
    }
    cout << ans;
    return 0;
}


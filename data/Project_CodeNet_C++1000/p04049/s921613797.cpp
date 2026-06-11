#pragma GCC optimize("Ofast,fast-math,unroll-loops")
  
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
  
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
//using namespace __gnu_pbds;
         
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using pld = pair <ld, ld>;
 
/*
const ll MAX_MEM = 5e8;
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
    //freopen("circlecover.in", "r", stdin);
    //freopen("circlecover.out", "w", stdout);
}

const int INF = 1e9;

signed main()
{
    Start();
    int n, k;
    cin >> n >> k;
    vector <vector <int>> g(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int bst = 0;
    vector <int> d(n, INF);
    if (k % 2 == 0)
    {
        for (int i = 0; i < n; ++i)
        {
            vector <int> cur;
            queue <int> q;
            q.emplace(i);
            d[i] = 0;
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                cur.pb(v);
                for (auto &to : g[v])
                {
                    if (d[to] > d[v] + 1 && d[v] + 1 <= k / 2)
                    {
                        d[to] = d[v] + 1;
                        q.emplace(to);
                    }
                }
            }
            bst = max(bst, (int)cur.size());
            for (auto &v : cur)
                d[v] = INF;
        }
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j : g[i])
            {
                vector <int> cur;
                queue <int> q;
                q.emplace(i);
                d[i] = 0;
                q.emplace(j);
                d[j] = 0;
                while (!q.empty())
                {
                    int v = q.front();
                    q.pop();
                    cur.pb(v);
                    for (auto &to : g[v])
                    {
                        if (d[to] > d[v] + 1 && d[v] + 1 <= k / 2)
                        {
                            d[to] = d[v] + 1;
                            q.emplace(to);
                        }
                    }
                }
                bst = max(bst, (int)cur.size());
                for (auto &v : cur)
                    d[v] = INF;
            }
        }
    }
    cout << n - bst;
    return 0;
}


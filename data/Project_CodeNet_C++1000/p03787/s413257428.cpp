#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned ui;
typedef unsigned long long ul;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef pair<ul, ul> puu;
typedef vector<int> vi;
#define pb push_back
#define fi first
#define se second
#define ls (i << 1)
#define rs (i << 1 | 1)
#define mid (l + r >> 1)
#define enum(i, j, k) for(int i = j; i <= (k); i ++)
#define open(i, j, k) for(int i = j; i <  (k); i ++)
#define dec(i, j, k)  for(int i = j; i >= (k); i --)
#define ae(x) for(node *p = h[x]; p; p = p->nxt)
#define mfil(x, k) memset(x, k, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
#define fio(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
template <class T> bool chkmin(T &x, T y)
{ return y < x ? (x = y, true) : false; }
template <class T> bool chkmax(T &x, T y)
{ return y > x ? (x = y, true) : false; }
struct __init { __init()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cout.precision(16); cout << fixed;
    srand(time(0) ^ ui(ul(new char)));
} } static __init__;
/* default code ends here */

const int maxn = 2e5 + 10;
int n, m;
vi h[maxn];
int fa[maxn];
bool ji[maxn];
int getfa(int x)
{
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
void merge(int x, int y)
{
    int f1 = getfa(x), f2 = getfa(y);
    if(f1 != f2)
        fa[f1] = f2;
}

int col[maxn];

void dfs(int x)
{
    for(int v : h[x])
    {
        if(!col[v])
        {
            col[v] = 3 - col[x];
            dfs(v);
        }
        else if(col[v] == col[x])
            ji[getfa(x)] = true;
    }
}

int main()
{
    cin >> n >> m;
    enum(i, 1, n)
        fa[i] = i;
    int u, v;
    enum(i, 1, m)
    {
        cin >> u >> v;
        merge(u, v);
        h[u].pb(v);
        h[v].pb(u);
    }
    enum(i, 1, n)
        if(!col[i])
        {
            col[i] = 1;
            dfs(i);
        }
    
    ll ans = 0, jt = 0, ot = 0;
    enum(i, 1, n)
        if(!h[i].empty() && fa[i] == i)
        {
            if(ji[i])
            {
                ans += jt + ot;
                jt ++;
            }
            else
            {
                ans += jt + 2 * ot;
                ot ++;
            }
        }
    //cerr << jt << ' ' << ot << endl;
    ans *= 2;
    ans += jt + 2 * ot;
    ll tot = 0;
    enum(i, 1, n)
        tot += h[i].empty();
    ans += 2 * tot * n - tot * tot;
    cout << ans << '\n';
    return 0;
}
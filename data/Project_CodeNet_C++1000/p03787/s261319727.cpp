/// b.cpp

# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;
const pair < int , int > DD[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
# define fi cin
# define fo cout
# define x first
# define y second
# define ll long long
# define IOS ios_base :: sync_with_stdio(0);cin.tie(0)
# define p(v) cerr << #v << " = " << v << '\n'
# define p2(v) cerr << #v << " = " << (complex < __typeof(v.x) > (v.x,v.y)) << '\n'
# define vi vector < int >
# define vl vector < ll >
# define pll pair < ll , ll >
# define pii pair < int , int >
# define mp make_pair
# define db long double
# define fail puts("-1")
# define yes puts("YES")
# define no puts("NO")
# define PP puts("Possible")
# define II puts("Impossible")
# define vii vector < pii >
# define vll vector < ll >
# define pb push_back
# define pdd pair < db , db >
template < class T > T smin(T &a,T b) {if (a > b) a = b;return a;}
template < class T > T smax(T &a,T b) {if (a < b) a = b;return a;}
int main(void)
{
    #ifdef CF
    freopen("input","r",stdin);
    #endif // CF
    srand(time(0));
    fo << fixed << setprecision(7);
    cerr << fixed << setprecision(7);
    int n,m;
    fi>>n>>m;
    static vi g[1 << 20];
    while (m --)
    {
        int a,b;
        fi>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    static int was[1 << 20];
    static int mark[1 << 20];
    vi vertices;
    function < void(int) > dfs = [&](int node)
    {
        vertices.pb(node);
        was[node] = 1;
        for (auto it : g[node])
            if (!was[it])
                mark[it] = mark[node] ^ 1,dfs(it);
    };
    int a = 0,b = 0,c = 0;
    for (int i = 1;i <= n;++i)
        if (!was[i])
        {
            vertices.clear();
            dfs(i);
            if (vertices.size() == 1)
                ++a;
            else
            {
                int w = 1;
                for (auto v : vertices)
                    for (auto it : g[v])
                        w &= mark[v] ^ mark[it];
                b += w;
                c += 1 - w;
            }
        }
    fo << (2ll * n * a - 1ll * a * a + 1ll * (b + c) * (b + c) + 1ll * b * b) << '\n';
    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
    return 0;
}

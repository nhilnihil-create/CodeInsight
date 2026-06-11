/// a.cpp

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
    int n;
    const int mod = 1e9 + 7;
    fi>>n;
    vi s;
    int ans = 1;
    int cnt = 0;
    for (int i = 1;i <= n;++i)
    {
        int v;
        fi>>v;
        if (v <= cnt + cnt)
            ans = (1ll * ans * (cnt + 1)) % mod;
        else
            ++cnt;
    }
    while (cnt --) ans = (1ll * ans * (cnt + 1)) % mod;
    fo << ans << '\n';
    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
    return 0;
}

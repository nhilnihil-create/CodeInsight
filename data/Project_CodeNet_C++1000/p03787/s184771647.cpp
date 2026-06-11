#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int LL;
typedef LL ll;
typedef long double ld;
typedef string str;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef stringstream strs;
 
#define X first
#define Y second
#define PB push_back
#define For(i,a,b) for (int i=a;i<b;i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define smax(a,b) a=max(a,b)
#define smin(a,b) a=min(a,b)
#define SZ(a) ((ll)a.size())
#define ER(a) cout << #a << ' ' << a << endl
#define LB(a,n,x) (lower_bound(a,(a)+(n),x)-(a))
#define RET(x) { cout << x; exit(0); } 
const ll M=2e5+5,LG=19,SM=600+5,inf=1e18+1;
ll mod=1e9+7;

ll n,a,b,c,m;
vll g[M];
ll mark[M];
bool ba2;

void dfs(ll x)
{
    for (ll y:g[x])
    {
        if (mark[y])
        {
            ba2|=(mark[x]==mark[y]);
            continue;
        }
        mark[y]=(mark[x]==1?2:1);
        dfs(y);
    }
}

int main()
{
	ios::sync_with_stdio(0);
    cin >> n >> m;
    For(i,0,m)
    {
        ll u,v;
        cin >> u >> v;
        u--;v--;
        g[u].PB(v);g[v].PB(u);
    }
    a=n;
    For(i,0,n)
    {
        if (SZ(g[i])==0)
        {
            a--;
            continue;
        }
        if (mark[i]) continue;
        ba2=0;
        mark[i]=1;
        dfs(i);
        b++;
        c+=1-ba2;
    }
    //ER(a);ER(b);ER(c);
    ll res=n*n;
    res-=a*a;
    res+=b*b;
    res+=c*c;
    RET(res);    
}    
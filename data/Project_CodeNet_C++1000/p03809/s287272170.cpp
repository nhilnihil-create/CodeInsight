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

ll n;
str z[2]={"YES","NO"};
vll g[M];
ll a[M];

ll dfs(ll x,ll p)
{
    //ER(x);
    if (SZ(g[x])==1) return a[x];
    vll s;
    ll su=0;
    for (ll y:g[x])
    {
        if (y==p) continue;
        s.PB(dfs(y,x));
        su+=s.back();
    }
    if (a[x]>su) RET(z[1]);
    ll tp=su-a[x];
    ll fn=su-2*tp;
    sort(s.begin(),s.end());
    ll mx=s.back();
    if (mx<=su-mx) tp-=su/2;
    else tp-=su-mx;
    if (tp>0) RET(z[1]);
    //ER(x);ER(fn);
    return fn;
}

int main()
{
	ios::sync_with_stdio(0);
    cin >> n;
    For(i,0,n)
    {
        cin >> a[i];    
    }
    For(i,1,n)
    {
        ll u,v;
        cin >> u >> v;
        u--;v--;
        g[u].PB(v);g[v].PB(u);
    }
    if (n==2) RET(z[a[0]!=a[1]]);
    ll root;
    For(i,0,n)
    {
        if (SZ(g[i])>1) { root=i; break;}
    }
    root=dfs(root,root);
    RET(z[root!=0]);
}    
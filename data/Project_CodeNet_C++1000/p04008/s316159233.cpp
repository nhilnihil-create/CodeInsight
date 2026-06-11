#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int LL;
typedef LL ll;
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
const ll M=2e5+5,LG=19,SM=4000+5,inf=1e18+1;
ll mod=1e9+7;

ll par[M];
vll ch[M];
ll n,k,res;

ll dfs(ll x)
{
    ll h=1;
    for (ll y:ch[x])
    {
        if (y==par[x]) continue;
        smax(h,dfs(y)+1);       
    }
    if (h==k && par[x]!=0)
    {
        res++;
        return 0;
    }
    return h;
}

int main()
{
	ios::sync_with_stdio(0);
    cin >> n >> k;
    cin >> par[0];
    res=par[0]!=1;
    par[0]=0;
    For(i,1,n)
    {
        cin >> par[i];
        par[i]--;
        ch[par[i]].PB(i);
    }
    dfs(0); 
    RET(res);     
}
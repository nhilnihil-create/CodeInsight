#include <bits/stdc++.h>
using namespace std;
#define ll          long long int
#define pb          push_back
#define pll         pair<ll,ll>
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mode        998244353
#define mod         1000000007
#define inf         1000000000000000000LL
#define vl          vector<ll>
#define F           first
#define S           second
#define db          long double
#define sz(x)       (ll)x.size()
#define fix(n)      cout<<fixed<<setprecision(n)
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define all(x)      x.begin(),x.end()
#define mset(x)     memset(x,0,sizeof x)
#define pi          3.14159265358979323

const int N = 303;

ll n, m, a[N][N], ans=500;
bool vis[N];
ll cnt[N];

void solve()
{
       cin>>n>>m;
       rep(i,1,n+1) rep(j,1,m+1) cin>>a[i][j];
       vis[0]=1;
       rep(k,1,m+1)
       {
              mset(cnt);
              ll mx=-1, pos=1;
              rep(i,1,n+1)
              {
                     rep(j,1,m+1)
                     {
                            if(!vis[a[i][j]])
                            {
                                   cnt[a[i][j]]++;
                                   break;
                            }
                     }
              }
              rep(i,1,m+1) if(mx<cnt[i]) { mx=cnt[i]; pos=i; }
              vis[pos]=1;
              ans=min(ans,mx);
       }
       cout<<ans;
}


int main()
{
    speed_up
    ll T=1;
    //cin>>T;
    while(T--)
        solve();
    return 0;
}

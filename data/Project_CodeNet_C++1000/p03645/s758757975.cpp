
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'
#define         pii        pair<int,int>
#define         mapii      map<int,int>
#define         mapll      map<ll,ll>
#define         mapci      map<char,int>
#define         mapcl      map<char,ll>
#define         mapsi      map<string,int>
#define         mapsl      map<string,ll>
#define         pll        pair<ll,ll>
#define         vi         vector<int>
#define         vl         vector<ll>
#define         vd         vector<double,double>
#define         all(c)     c.begin(),c.end()
#define         F          first
#define         S          second
#define         mp         make_pair
#define        ftc(x)      cerr << #x << ": " << x << " " << endl;
#define         PI         acos(-1)
#define         lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))

vi ad[200009];
int dis[200009];
bool vis[200009];

void dfs(int x)
{
    vis[x] = 1;

    for(auto u : ad[x])
    {
        if(!vis[u] && dis[x]+1 < dis[u])
        {
            dis[u] = dis[x]+1;
            dfs(u);
        }
    }
}

int main()
{

    int n,m,i,j,k,l,u,v;

    cin >> n >> m;

    for(i=0;i<m;i++)
    {
        cin >> u >> v;

        ad[u].pb(v);
        ad[v].pb(u);
    }

   bool faltu = false;

   for(auto x : ad[1])
   {
       if(x == n)faltu = true;

       for(auto kk : ad[x])
       {
           if(kk == n)faltu = true;
       }
   }
    if(faltu)cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
//    ll i,j,k,n,x,m;
//
//    cin >> n>> x;
//ll ar[n+10];
//
//ll cnt = 0;
//    for(i=0;i<n;i++)
//    {
//        cin >> ar[i];
//    }
//
//    for(i=1;i<n;i++)
//    {
//        m = ar[i]+ar[i-1];
//        if(m>x)
//        {
//            ll baki = m-x;
//
//            ar[i] -= baki;
//            cnt += baki;
//        }
//    }
//
//    cout << cnt << endl;
}

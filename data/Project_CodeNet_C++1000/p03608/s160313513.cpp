#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define eb emplace_back
//#define st first
#define sc second

using namespace std;

const ll mod = 1e9 + 7;
const int e = 1e5 + 69;
const int base = 311;

// dung inverse module de tinh nCk
// beginer 73
// mbeginer
// cach tao hoan vi tu n so : n*(n+1)/2;

//vector<pair<ll,ll>>adj[e];

ll Pow(ll n, ll dem)
{
    if(dem == 0) return 1;
    if(dem == 1) return n ;
    ll t = Pow(n, dem/2);
    if(dem % 2 == 0) return (t*t);
    else return ((t * t) * n);
}

/*ll C(ll k, ll n)
{
    if(k == 0) return 1;
    if(n < k) return 0;
    return (gt[n]%mod * (igt[k]%mod * igt[n-k]%mod)%mod)%mod;
}*/

int n, m, k;

ll a[e];

int main()
{
   cin >> n >> m >> k;
   vector<vector<ll>>adj(n+1, vector<ll>(n+1, 1e18));
   for(int i=1; i<=k; i++)
   {
       cin >> a[i];
   }
   for(int i=1; i<=m; i++)
   {
       ll u, v, w;
       cin >> u >> v >> w;
       adj[u][v] = min(adj[u][v], w);
       adj[v][u] = min(adj[v][u], w);
   }
   for(int z=1; z<=n; z++)
   {
       for(int i=1; i<=n; i++)
       {
           for(int j=1; j<=n; j++)
           {
               if(adj[i][j] > adj[i][z] + adj[z][j])
               {
                   adj[i][j] = adj[i][z] + adj[z][j];
               }
           }
       }
   }
   ll ans = 1e18;
   ll curr = 0;
   sort(a+1, a+k+1);
   for(int i=1; i<k; i++)
   {
       curr += adj[a[i]][a[i+1]];
   }
   ans = min(ans, curr);
   while(next_permutation(a+1, a+k+1))
   {
       ll cur = 0;
       for(int i=1; i<k; i++)
       {
           //cout << a[i] << " ";
           cur += adj[a[i]][a[i+1]];
       }
       //cout << endl;
       ans = min(ans, cur);
   }
   cout << ans;
}
/*

*/

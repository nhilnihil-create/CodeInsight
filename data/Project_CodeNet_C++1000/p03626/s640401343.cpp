#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define eb emplace_back
//#define st first
#define sc second

using namespace std;

const ll mod = 1e9 + 7;
const int e = 55;
const int base = 311;

// dung inverse module de tinh nCk
// 71
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

ll n, m, k;
ll gt[e];
char a[e][e];

int main()
{
   ll n;
   cin >> n;
   ll ans = 0;
   for(int i=1; i<=2; i++)
   {
       for(int j=1; j<=n; j++)
       {
           cin >> a[i][j];
       }
   }
   ll chk ;
   for(int i=1; i<=n; i++)
   {
       if(a[1][i] == a[2][i])
       {
           if(i == 1)
           {
               ans = (ans + 3)%mod;
           }
           else
           {
               if(chk == 1)
               {
                   ans = (ans + ans)%mod;
               }
           }
           chk = 1;
       }
       else
       {
           if(i == 1)
           {
               ans = 6;
           }
           else
           {
               if(chk == 1)
               {
                   ans = (ans*2)%mod;
               }
               else
               {
                   ans = (ans*3)%mod;
               }
           }
           chk = 2;
           i ++;
       }
   }
   cout << ans;
}
/*

*/

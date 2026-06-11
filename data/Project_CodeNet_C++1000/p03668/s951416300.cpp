/*   Abhijith  */
#include<bits/stdc++.h>
#include<iomanip>
#include<cmath>
#define lld long long int
#define ld long double
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define	endl '\n'
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<lld>     adj[300005];
lld dp[300005];
void dfs(lld s,lld par)
{
    lld sz=adj[s].size();
    if(sz==1&&s!=1)          //leaf node base condition
    {
        dp[s]=1;
        return;
    }
    lld ans1=0;
    for(lld i=0;i<sz;i++)
    {
        if(adj[s][i]==par)
            continue;
        dfs(adj[s][i],s);
        ans1=ans1^dp[adj[s][i]];
    }
    dp[s]=1+ans1;
}
int main()
{
      ios;
      lld x,y,n,m;
      cin>>n;
      m=n-1;
      rep(i,0,m-1)
      {
          cin>>x>>y;
          adj[x].pb(y);
          adj[y].pb(x);  //if graph is directed delete this line
      }
      dfs(1LL,0LL);
      if(dp[1]==1)
        cout<<"Bob"<<endl;
      else
        cout<<"Alice"<<endl;
    return 0;
}

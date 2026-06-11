#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n,k;cin>>n>>k;
  vector<int> a(n);
  int i,j;
  ll ans=20000000000;
  rep(i,n)cin>>a[i];
  rep(i,1<<n)
  {
    ll cost=0;
    int colors=0;
    rep(j,n)
    {
      if(1<<j&i)colors++;
    }
    if(colors<k)continue;
    int maxh=0;
    rep(j,n)
    {
      if((1<<j&i)&&maxh>=a[j])
      {
        cost+=maxh+1-a[j];
        maxh++;
      }
      else
      {
        maxh=max(maxh,a[j]);
      }
    }
    ans=min(ans,cost);
  }
  cout<<ans<<endl;
}


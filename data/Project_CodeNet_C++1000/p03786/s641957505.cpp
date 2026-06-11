#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n;cin>>n;
  vector<ll> a(n);
  int i;
  rep(i,n)cin>>a[i];
  sort(all(a));
  vector<ll> sum(n+1,0);
  rep(i,n)sum[i+1]=sum[i]+a[i];
  int ans=1;
  for(i=n-1;i>=1;i--)
  {
    if(sum[i]*2>=a[i])
    {
      ans++;
    }
    else break;
  }
  cout<<ans<<endl;
}

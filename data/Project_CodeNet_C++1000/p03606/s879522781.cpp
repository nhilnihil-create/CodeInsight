
#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{
    int n;
    cin>>n;
  int ans=0;
  for(int i=1;i<=n;i++)
  {
      int x,y;
      cin>>x>>y;
      ans+=abs(x-y)+1;
  }
    cout<<ans<<endl;
}
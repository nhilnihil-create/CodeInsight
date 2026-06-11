#include<bits/stdc++.h>
using namespace std;

#define int long long int 


int32_t main()
{
  int n;
  cin>>n;
  int a[n];
  int ans=0;
  int ans1=0;
  int ans2=0;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    if(x%2!=0 && x%4!=0)
    ans++;
    else if(x%4==0)
    ans1++;
    else if(x%2==0)
     ans2++;
  }
//  cout<<ans1<<" "<<ans<<" "<<ans2<<endl;
  if(ans==0 ||ans1&&!ans||ans2&&!ans||  (!ans2 && ans1>=(ans-1)) || (ans2 &&ans1>=ans ))
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
}
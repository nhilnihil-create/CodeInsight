#include <bits/stdc++.h>
using namespace std;
int a[1000000],ans;
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n*2;i++)cin>>a[i];
  sort(a,a+2*n);
  for(int i=0;i<n*2;i+=2)
  ans+=a[i];
  cout<<ans<<endl;
  return 0;
}

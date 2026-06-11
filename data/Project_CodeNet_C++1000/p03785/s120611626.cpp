#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,c,k;
  cin>>n>>c>>k;
  vector<int>t(n);
  for(int i=0;i<n;i++)cin>>t[i];
  sort(t.begin(),t.end());
  int count=0;
  int bus=0;
  int tlim=0;
  for(int i=0;i<n;i++)
  {
    if(i==0)
    {
      count++;
      tlim=t[i]+k;
      continue;
    }
    if(count==c || tlim<t[i])
    {
      bus++;
      count=1;
      tlim=t[i]+k;
    }
    else count++;
  }
  cout<<bus+1<<endl;
  return 0;
}

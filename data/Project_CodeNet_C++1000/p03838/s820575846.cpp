#include<bits/stdc++.h>
using namespace std;
int main()
{
  int x,y;
  cin>>x>>y;
  long long ans=0;
  if(abs(x)==abs(y))ans=0+(x==-y && x!=0)*1;
  else if(x>y)
  {
    ans+=abs(abs(x)-abs(y))-(x>=0 && y<=0) +2 ;
  }
  else if(x<y)
  {
    ans+=abs(abs(y)-abs(x))+(x<0 && y>0);
  }
  cout<<ans<<endl;
  return 0;
}
    
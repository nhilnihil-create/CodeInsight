#include<iostream>
using namespace std;
int main()
{
  int n,k,x,y,i,sum=0;
  cin>>n;
  cin>>k;
  cin>>x;
  cin>>y;
  for(i=1;i<=n;i++)
  {
    if(i<=k)
    {
      
    sum+=x;
      
    }
    else
    {
      sum+=y;
    }
  }
  cout<<sum<<endl;
  return 0;
}

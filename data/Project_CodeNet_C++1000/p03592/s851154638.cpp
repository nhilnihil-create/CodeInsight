#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,k;
  cin>>n>>m>>k;
  if(k%n==0 || k%m==0)
  {
    cout<<"Yes"<<endl;
    return 0;
  }
  int flag=0;
  for(int i=1;i<=m;i++)
  {
    if((2*i)==m)continue;
    if((i*n)>k && ((i*n)-k)%((2*i)-m)==0 && (2*i)>m && ((i*n)-k)/((2*i)-m)<=n )
    {
      cout<<"Yes"<<endl;
      flag=1;
      break;
    }
    if((i*n)<k && (k-(i*n))%(m-(2*i))==0 && (2*i)<m && (k-(i*n))/(m-(2*i))<=n)
    {
      cout<<"Yes"<<endl;
      flag=1;
      break;
    }   
  }
  if(!flag)cout<<"No"<<endl;
  return 0;
}
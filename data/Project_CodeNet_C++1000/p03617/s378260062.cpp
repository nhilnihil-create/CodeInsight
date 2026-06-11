#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
long long a[5];
long long f[5],n,ss;
int main()
{
  cin>>a[1]>>a[2]>>a[3]>>a[4]>>n;
  f[4]=1;
  ss=a[4];
  a[1]*=4,a[2]*=2,a[4]/=2;
  for(int i=1;i<4;i++)
    for(int j=i;j<=4;j++)
      if(a[j]<a[i]){swap(a[i],a[j]);swap(f[i],f[j]);}
  if(f[1]==1)
    cout<<ss*(n/2)+(n%2)*a[2]<<endl;
  else
    cout<<a[1]*n<<endl;
  return 0;
}

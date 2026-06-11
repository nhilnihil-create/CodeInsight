#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a[3],i;
  for(i=0;i<3;i++)
  {
    cin>>a[i];
  }
  sort(a,a+3);
  int c=a[0]+a[1];
  int d=a[2];
  if(c==d)
  {
    cout<<"Yes";
  }
  else
  {
    cout<<"No";
  }
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a[3];
  int five=0;
  int seven=0;
  for(int i=0;i<3;i++)
{
cin>>a[i];
    if(a[i]%5==0)
    {
      five++;
    }
    if(a[i]%7==0)
    {
      seven++;
    }
}
 
  if(five==2&&seven==1)
  {
    cout<<"YES"<<endl;
  }
  else 
  {
    cout<<"NO"<<endl;
  }
  return 0;
}
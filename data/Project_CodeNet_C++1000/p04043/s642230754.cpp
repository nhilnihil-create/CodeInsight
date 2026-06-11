#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a[3];
  int x=0,y=0;
  for(int i=0;i<3;i++)
  {
    cin>>a[i];
    if(a[i]==5)
    {
      x++;
    }
    else y++;
  }
  if(x==2)
  {
    cout<<"YES";
  }
  else 
    cout<<"NO";
}

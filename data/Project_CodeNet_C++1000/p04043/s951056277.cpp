#include<iostream>
using namespace std;

int main()
{
  int n;
  int f = 0,s = 0;
  for(int i=0;i<3;i++)
  {
    cin>>n;
    if(n==5)
    {
      f++;
    }
    if(n==7)
    {
      s++;
    }
  }
  if(f==2&&s==1)
  {
    cout<<"YES";
  }
  else
  {
    cout<<"NO";
  }
}
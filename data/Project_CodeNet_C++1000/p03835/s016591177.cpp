#include<iostream>
using namespace std;
int main()
{
  int a,b,ans=0;
  cin>>a>>b;
  for(int i=0;i<=a;i++)
    for(int k=0;k<=a;k++)
      if(a>=b-i-k&&0<=b-k-i)
      {
          ans++;
          continue;
      }
  cout<<ans;
}
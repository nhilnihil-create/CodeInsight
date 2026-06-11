/*
/ ATcoder /
ID : lalit kumar
TASK : A
LANG : c++14
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
  cin>>n;
  int ans = -1;
  int pos;
  for(int i =1;i<=n;i++)
  {
      int m = 0;
      int j = i;
   while(j%2==0)
   {
    m++;
    j/=2;
   }
  if(m>ans)
  {
    ans = m;
    pos=i;
  }
 }
 cout<<pos<<endl;
}
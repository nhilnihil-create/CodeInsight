#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  int i,j,l;
  cin>>s;
  l=s.size();
  int count=0;
  for(i=0;i<l;i++)
  {
    for(j=0;j<l;j++)
    {
      if(s[i]==s[j])
         {
           count++;
         }
         
     }
    if(count%2==0)
    
      continue;
    else
      break;
    
  }
         if(count%2==0)
         {
           cout<<"Yes";
         }
         else
         {
           cout<<"No";
         }
    return 0;
}

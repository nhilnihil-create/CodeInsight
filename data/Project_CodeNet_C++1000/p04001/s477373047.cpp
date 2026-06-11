#include<bits/stdc++.h>
using namespace std;
string s;
int cnt=0;
long long ans=0;
int main()
{
  cin>>s;
  int g=s.size();
  for(int i=0;i<(1<<(g-1));i++)
    {
      long long m=s[0]-'0';
      for(int j=0;j<g-1;j++)
        {
          if(i&(1<<j))
           {
             ans+=m;
             m=0;
           }
          m=m*10+s[j+1]-'0';
        }
      ans+=m;
    }
  cout<<ans<<endl;
  return 0;
}
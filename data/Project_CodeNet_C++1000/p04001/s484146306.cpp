#include<bits/stdc++.h>
using namespace std;
string s;
long long ans=0;
long long tom(long long a,long long b,long long c,string d)
{
  long long r=0;
  if(a==d.size())
   return c;
  int t=d[a]-'0';
  if(a+1!=d.size())
   r+=tom(a+1,b*10+t,c,d);
   r+=tom(a+1,0,c+b*10+t,d);
  return r;
}
int main()
{
  while(cin>>s)
      {
        ans=tom(0,0,0,s);
        cout<<ans<<endl;
      }
  return 0;
}
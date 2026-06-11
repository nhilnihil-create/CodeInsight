#include<bits/stdc++.h>
using namespace std;
string s;
int cnt=0;
long long a[20],ans=0;
void tom(int l,int w)
{
  if(l==0)
   {
     if(w!=s.size())
      return ;
     if(cnt==0)
      for(int i=0;i<s.size();i++)
        ans=ans*10+s[i]-'0';
     else
        for(int i=1;i<=cnt;i++)
          ans+=a[i];
     return ;
   }
  for(int i=1;i<=s.size()-w;i++)
    {
      cnt++;
      for(int j=1;j<=i;j++)
        a[cnt]=a[cnt]*10+(s[w+j-1]-'0');
      tom(l-1,w+i);
      a[cnt]=0;
      cnt--;
    }
}
int main()
{
  cin>>s;
  for(int i=1;i<=s.size();i++)
    tom(i,0);
  cout<<ans<<endl;
  return 0;
}
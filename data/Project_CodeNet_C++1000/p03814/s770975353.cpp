#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long  j,b,w=0,n,i,c=0;
   string s;
   cin>>s;
for(i=0;i<s.size();i++)
{
  if(s[i]=='A')
  {
    c=i;
    break;
  }
}
for(j=s.size()-1;j>=0;j--)
{
  if(s[j]=='Z')
  {
    w=j;
    break;
  }
}
cout<<w-c+1<<endl;
return 0;
}

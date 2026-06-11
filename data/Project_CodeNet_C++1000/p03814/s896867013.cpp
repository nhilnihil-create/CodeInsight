#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;cin>>s;int a=-1,z;
  for(int i=0;i<s.size();i++)
  {
    if(a==-1&&s[i]=='A')a=i;
    if(s[i]=='Z')z=i;
  }
  printf("%d",z-a+1);
}
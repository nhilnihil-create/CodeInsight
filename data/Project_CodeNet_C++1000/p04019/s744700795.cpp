#include<bits/stdc++.h>
using namespace std;

int main()
{
  string S;cin>>S;
  int N=0,W=0,s=0,E=0;
  for(int i=0;i<S.size();i++)
  {
    if(S[i]=='N'&&N==0)N++;
    if(S[i]=='W'&&W==0)W++;
    if(S[i]=='S'&&s==0)s++;
    if(S[i]=='E'&&E==0)E++;
  }
  if(N==s&&W==E)printf("Yes\n");
  else printf("No\n");
}
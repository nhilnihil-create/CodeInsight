#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s="CODEFESTIVAL2016",ss;
  int ans=0;
  cin>>ss;
  for(int i=0;i<16;i++)
  if(s[i]!=ss[i]) ans++;
  cout<<ans<<endl;
  return 0;
}
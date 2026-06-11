#include<bits/stdc++.h>
using namespace std;

int main()
{
string S;cin>>S;string ans="yes";
set<char> Set;
for(int i=0;i<S.size();i++)
{
  if(!Set.count(S[i]))Set.insert(S[i]);
  else ans="no";
}
cout<<ans;
}
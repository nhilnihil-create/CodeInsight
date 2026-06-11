#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<char,int>mp;
    string s;
    int i;
    cin>>s;
    int n=s.size();

    for(i=0;i<n;i++)
        mp[s[i]]++;

  for(char j='a';j<='z';j++)
  {
      if(mp[j]%2)
      {
          cout<<"No\n";
          return 0;
      }
  }
  cout<<"Yes\n";
  return 0;
}

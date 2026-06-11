#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,l;cin>>n>>l;
  string s;vector<string>v;
  for(int i=0;i<n;i++)
  {
    cin>>s;
    v.push_back(s);
  }
  sort(v.begin(),v.end());
  for(auto w:v)
  {
    cout<<w;
  }
  return 0;
}
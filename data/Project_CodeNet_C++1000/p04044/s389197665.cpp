#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  
  int n,i,l,j;
  cin>>n>>l;
  string s;
  vector<string>v;
  
  for(i=0;i<n;i++)
  {
      cin>>s;
      v.push_back(s);
  }

  sort(v.begin(),v.end());
  
  for(i=0;i<n;i++)
  {
      for(j=0;j<l;j++)cout<<v[i][j];
  }

}
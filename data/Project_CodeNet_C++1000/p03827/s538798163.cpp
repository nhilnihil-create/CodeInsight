#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  vector<int>v;
  v.push_back(0);
  int x=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='I')
    {
      x+=1;
    }
    else{
      x-=1;
    }
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  cout<<v[v.size()-1];
}  

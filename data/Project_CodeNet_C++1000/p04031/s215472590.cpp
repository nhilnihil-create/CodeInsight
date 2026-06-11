#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,ans=INT_MAX;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)
    cin>>v[i];
  for(int i=-100;i<=100;i++)
  {
    int cost=0;
    for(int j=0;j<v.size();j++)
      cost=cost+pow(i-v[j],2);
    if(cost<ans)
      ans=cost;
  }
  cout<<ans;
  return 0;
}
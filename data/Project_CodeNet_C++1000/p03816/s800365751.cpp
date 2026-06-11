#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int x;set<int> s;
  for(int i=0;i<n;i++){cin>>x;s.insert(x);}
  int k=s.size();
  if(k&1)cout<<k;
  else cout<<k-1;
}
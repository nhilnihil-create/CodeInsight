#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
 int n,k,x,y;
  cin>>n>>k>>x>>y;
  int amt = min(k,n);
  amt *= x;
  if(k < n)
  {
    int cur = (n-k)*y;
    amt += cur;
  }
  cout<<amt<<endl;
  return 0;
}
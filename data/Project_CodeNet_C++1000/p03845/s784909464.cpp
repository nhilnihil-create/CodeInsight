#include<bits/stdc++.h>
using namespace std;
int main()
{
long int sum,n,m,i;
  sum=0;
  cin >> n;
int t[n];
  
  for(i=0;i<n;++i)
  {
  cin >> t[i];
  sum=sum+t[i];
  }
  cin >> m;
int p[m],x[m];
  
  for(i=0;i<m;++i)
  {
  cin >> p[i] >> x[i];
  cout << sum-t[p[i]-1]+x[i] << endl;
  }

return 0;}
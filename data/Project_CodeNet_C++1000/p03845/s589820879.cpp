#include<bits/stdc++.h>
using namespace std;
int main()
{
  long int n; cin>>n;
  int t[n];
  long int sum=0;
  for(int i=0;i<n;i++){  cin>>t[i]; sum+=t[i];  }
  int m;  cin>>m;
  int p[m],x[m];
  for(int i=0;i<m;i++)
  {
    cin>>p[i]>>x[i];
  }
  
  for(int i=0;i<m;i++)
  {
    cout<<sum-t[p[i]-1]+x[i]<<"\n";
  }

  return 0;
}
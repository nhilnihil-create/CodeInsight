#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
  int ara[n+5];
  for(int i=0;i<n;i++)cin>>ara[i];
  sort(ara,ara+n);
  reverse(ara,ara+n);
  int sum=0;
  for(int i=0;i<k;i++)sum+=ara[i];
  cout<<sum<<endl;
}
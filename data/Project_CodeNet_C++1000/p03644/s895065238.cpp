#include<bits/stdc++.h>
using namespace std;


#define int long long int 

int32_t main()
{
  int n;
  cin>>n;
  int ans=0;
  int p=2;
  while(p<=n)
    p=p*2;
  
  cout<<p/2<<endl;
}
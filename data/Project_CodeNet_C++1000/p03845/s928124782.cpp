//#pragma GCC target ("1avx2")
#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back 
const int M=10000000000;
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

signed main()
{
  fastio;
  int t=1;
  //cin>>t;
  while(t--)
  {
    int n,sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      sum+=arr[i];
    }
    
    int m,p,x;
    cin>>m;
    for(int i=0;i<m;i++)
    {
      cin>>p>>x;
      cout<<sum+x-arr[p-1]<<"\n";
    }
  }
  return 0;
}

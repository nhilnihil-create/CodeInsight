#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pb push_back 
const int M=1000000007;
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int modpow(int x, int n , int m)
{
 if(n==0)
  return 1;
 else if(n%2==0)
  return modpow((x*x)%m,n/2,m);
 else
  return (x*modpow((x*x)%m,n/2,m))%m;
}
signed main()
{
  fastio;
  int t=1;
  //cin>>t;
  while(t--)
  {
    int n,zero=0,flag=0;
    cin>>n;
    int arr[n];
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      mp[arr[i]]++;

      if(arr[i]==0)
        zero++;

      if(mp[arr[i]]>2)
        flag=1;
    }

    for(auto x:mp)
    {
      if(x.first && x.second!=2)
      {
        flag=1;
        break;
      }
    }

    if(flag || (n&1 && zero>1))
    {
      cout<<"0";
      return 0;
    }

    if(n%2==0 && zero!=0)
    {
      cout<<"0";
      return 0;
    }
    
    if(n%2==0)
      cout<<modpow(2,n/2,M);
    else
    {
      n--;
      cout<<modpow(2,n/2,M);
    }
  }
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  int n,k;
  cin>>n>>k;
  int ans=0;
  for (int i = 0; i < n; ++i)
  {
    int x;
    cin>>x;
    ans+=2*min(abs(k-x),x);
  }
  cout<<ans<<endl;
}
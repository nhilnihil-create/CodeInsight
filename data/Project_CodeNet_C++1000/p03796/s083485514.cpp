#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;
#define nl '\n'
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve()
{
  long long n,r=1;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    r*=i;
    r%=mod;
  }
  cout<<r<<nl;
}

int main()
{
    fio;
    solve();
    return 0;
}

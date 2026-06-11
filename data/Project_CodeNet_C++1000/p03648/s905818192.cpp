#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100];
int main(){
  ll k; int n=50;
  cin>>k;
  cout<<n<<endl;
  for (int i=1; i<=n; ++i)
    a[i]=n-1+k/n;
  k%=n;
  for (int i=1; i<=k; ++i)
    a[i]+=n-k+1;
  for (int i=k+1; i<=n; ++i)
    a[i]-=k;
  for (int i=1; i<=n; ++i)
    cout<<a[i]<<" ";
  return 0;
}

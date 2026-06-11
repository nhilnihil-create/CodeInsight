#include <bits/stdc++.h>
#define r(i,n) for(long long i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main() {
  int n;
  cin >> n;
  ll ans=10000000000000000;
  vector<ll> v(n,0),s(n,0);
  r(i,n){
    cin >> v[i];
    if(!i)s[i]=v[i];
    else s[i]=s[i-1]+v[i];
  }
  r(i,n-1){
    ans=min(ans,abs(s[n-1]-s[i]*2));
  }
  cout << ans << endl;
}
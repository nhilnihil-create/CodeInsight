#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  ll n, t;
  cin >> n >> t;
  ll a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  ll ans = t;
  for(int i=1; i<n; i++){
    ans += min(t, a[i]-a[i-1]);
  }
  cout << ans << endl;
  return 0;
}

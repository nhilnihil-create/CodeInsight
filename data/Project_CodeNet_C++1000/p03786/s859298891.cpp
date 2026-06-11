#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9+10;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  vector<ll> v(n);
  v[0] = a[0];
  rep(i,n-1) v[i+1] = v[i] + a[i+1];

  int ans = 1;
  int i = 0;
  while(n-2-i >= 0){
    if(2*v[n-2-i] >= a[n-1-i]) ans++;
    else break;
    i++;
  }
  cout << ans << endl;

  return 0;
}

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9+7;

int main(){
  int n;
  ll a[200000];
  cin>>n;
  for (int i(0);i<n;i++) cin>>a[i];
  ll sum(0);
  for (int i(0);i<n;i++) sum+=a[i];
  ll mini(1e18);
  ll sumi(0);
  for (int i(0);i<n-1;i++){
    sumi+=a[i];
    cerr<<abs(sumi-(sum-sumi))<<" ";
    mini=min(mini,abs(sumi-(sum-sumi)));
  }
  cout << mini << endl;
  return 0;
}

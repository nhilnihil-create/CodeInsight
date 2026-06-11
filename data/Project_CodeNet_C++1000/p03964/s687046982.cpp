#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  long double t[n], a[n];
  for ( int i = 0; i < n; i++){
    cin >> t[i] >> a[i];
    if ( i == 0)continue;
    if ( t[i] >= t[i-1] && a[i] >= a[i-1])continue;

    long double mul = max(ceil(t[i-1]/t[i]), ceil(a[i-1]/a[i]));
    t[i] = t[i] * mul;
    a[i] = a[i] * mul;
  }
  long long ans = t[n-1] + a[n-1];

  cout << ans << endl;

  return 0;
}
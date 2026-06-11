#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  ll T = 1, A = 1;
  for (int i=0; i<n; i++){
    ll t, a;
    cin >> t >> a;
    if (T%t) T = T + (t - T % t);
    if (A%a) A = A + (a - A % a);
    // cout << t << ' ' << a << endl;
    if (T/t > A/a) A = (T / t) * a;
    else if (T/t < A/a) T = (A / a) * t;
    // cout << T << ' ' << A << endl;
  }
  cout << T + A << endl;
  return 0;
}
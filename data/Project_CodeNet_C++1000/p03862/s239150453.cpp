#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
  ll N, x;
  cin >> N >> x;
  
  vector<ll> a(100010);
  
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  } 
  
  ll ans = 0;
  
  if (a[0] > x) {
    ans += a[0] - x;
    a[0] = x;    
  }
  
  for (int i = 0; i < N-1; i++) {
    if (a[i] + a[i+1] <= x) continue;
    
    ans += a[i] + a[i+1] - x;
    a[i+1] =  x - a[i];
  }
  
  cout << ans << endl;
}
#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  ll n, x;
  cin >> n >> x;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 0; i < n-1; i++){
    if (a[i] + a[i+1] > x){
      if (a[i] > x){
        ans += a[i]-x;
        ans += a[i+1];
        a[i] = x;
        a[i+1] = 0;
      }
      else {
        ans += a[i+1] + a[i] - x;
        a[i+1] = x-a[i];
      }
    }
  }
  cout << ans << endl;
  
  

  return 0;
}

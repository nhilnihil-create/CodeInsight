#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  ll sum = 0;
  ll m = INF;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
    m = min(m, a[i]);
  }

  ll l = n * (n + 1)/2;
  if (sum % l != 0 || sum / l > m){
    cout << "NO" << endl;
  }
  else {
    ll k = sum / l;
    bool ok = 1;
    for (int i = 0; i < n; i++){
      if (a[(i + 1) % n] % n != (a[i] + k) % n){
        ok = 0;
      }
    }

    if(ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
    


  return 0;
}

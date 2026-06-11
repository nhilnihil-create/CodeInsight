#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll k, t;
  cin >> k >> t;
  
  vector<ll> a(t);
  for (int i = 0; i < t; i++){
    cin >> a[i];
  }
  
  sort(a.begin(), a.end());
  
  ll s = 0;
  for (int i = 0; i < t - 1; i++){
    s += a[i];
  }

  cout << max(0LL, a[t-1] - s - 1) << endl;
  

  return 0;
}

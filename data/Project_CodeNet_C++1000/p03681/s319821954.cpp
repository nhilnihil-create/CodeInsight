#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  
  if(n < m) swap(n, m);
  long long ans = 0, mod = pow(10, 9) + 7;
  if(n - m > 1){
    cout << 0 << endl;
    return 0;
  }
  
  vector<long long> mu(n+1, 1);
  for(int i = 1; i <= n; i++){
    mu.at(i) = i * mu.at(i-1) % mod;
  }
  ans = mu.at(n) * mu.at(m) % mod;
  
  if(n - m == 1) cout << ans << endl;
  else cout << ans * 2 % mod << endl;
}
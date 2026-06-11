#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9+7, ans = 1;
int main(){
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) ans = ans*i%mod;
  cout << ans << endl;
}
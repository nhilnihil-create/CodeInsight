#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  long long mod = 1e9 + 7;
  long long ans = 1;
  for (int i=2; i<=n; i++) {
    ans *= i;
    ans %= mod;
  }
  cout<<ans<<endl;
}
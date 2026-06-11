#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int A, B, C, D; cin >> A >> B >> C >> D;
  int ans = 0;
  if (B <= C || D <= A) ans = 0;
  else ans = min(B, D)- max(A, C);
  
  cout << ans << endl;
  return 0;
}
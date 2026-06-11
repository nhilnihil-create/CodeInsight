#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n,k;
  cin >> n >> k;

  vector<int> x(n);
  rep(i,n) cin >> x[i];
  int ans = 0;
  
  rep(i,n) {
    int m = min(x[i], abs(x[i]-k));
    ans += 2*m;
  }

  cout << ans << endl;
}
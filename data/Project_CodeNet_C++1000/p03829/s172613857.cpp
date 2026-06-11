#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;
void solve(){
  ll n, a, b, ans = 0; cin >> n >> a >> b;
  vector<ll> x(n);
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }
  for(int i = 0; i < n - 1; i++){
    if((x[i + 1] - x[i]) * a <= b) ans += (x[i + 1] - x[i]) * a;
    else ans += b;
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int n, t; cin >> n >> t;
  vector<int> v(n), aida(n - 1);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  for(int i = 0; i < n - 1; i++){
    aida[i] = v[i + 1] - v[i];
  }
  long long ans = 0;
  for(int i = 0; i < n - 1; i++){
    if(aida[i] < t) ans += aida[i];
    else ans += t;
  }
  ans += t;
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}

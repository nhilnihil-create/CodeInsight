#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;
void solve(){
  long long x, ans = 0; cin >> x;
  ans = (x / 11) * 2;
  if(x % 11 >= 1 && x % 11 <= 6) ans += 1;
  else if(x % 11 >= 7) ans += 2;
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}

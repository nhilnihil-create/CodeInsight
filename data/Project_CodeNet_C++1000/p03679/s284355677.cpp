#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int x, a, b; cin >> x >> a >> b;
  if(b <= a) cout << "delicious\n";
  else if((b - a) <= x) cout << "safe\n";
  else cout << "dangerous\n";
  return;
}

int main(){
  solve();
  return 0;
}

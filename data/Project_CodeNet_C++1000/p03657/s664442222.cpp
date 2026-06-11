#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int a, b; cin >> a >> b;
  if(a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) cout << "Possible\n";
  else cout << "Impossible\n";
  return;
}

int main(){
  solve();
  return 0;
}

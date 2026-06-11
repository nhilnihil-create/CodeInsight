#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  string a, b, c; cin >> a >> b >> c;
  if(a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0]) cout << "YES\n";
  else cout << "NO\n";
  return;
}

int main(){
  solve();
  return 0;
}

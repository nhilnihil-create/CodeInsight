#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int a, b, c; cin >> a >> b >> c;
  if(c >= a && c <= b) cout << "Yes\n";
  else cout << "No\n";
  return;
}

int main(){
  solve();
  return 0;
}

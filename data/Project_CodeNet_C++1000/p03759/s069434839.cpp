#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int a, b, c;
  cin >> a >> b >> c;
  if(b - a == c - b) cout << "YES\n";
  else cout << "NO\n";
  return;
}

int main(){
  solve();
  return 0;
}

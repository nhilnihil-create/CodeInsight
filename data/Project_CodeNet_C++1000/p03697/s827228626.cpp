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
  if(a + b < 10) cout << a + b << endl;
  else cout << "error" << endl;
  return;
}

int main(){
  solve();
  return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  vector<int> a(3);
  for(int i = 0; i < 3; i++) cin >> a[i];
  sort(a.begin(), a.end());
  cout << a[0] + a[1] << endl;
  return;
}

int main(){
  solve();
  return 0;
}

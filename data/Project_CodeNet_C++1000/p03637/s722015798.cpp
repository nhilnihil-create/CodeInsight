#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int n; cin >> n;
  vector<long long int> a(n);
  int fn = 0, tn = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(a[i] % 4 == 0) fn++;
    else if(a[i] % 2 == 0) tn++;
  }
  if(tn > 0) n = n - tn;
  else n = n - 1;
  if((n + 1) / 2 <= fn) cout << "Yes\n";
  else cout << "No\n";

  return;
}

int main(){
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve() {
  string o, e;
  cin >> o >> e;
  int oz = (int) o.size();
  int ez = (int) e.size();
  int flag = 0;
  int lim = oz;
  if(oz > ez) {
    lim = ez;
    flag = 1;
  }
  else if (oz < ez) {
    lim = oz;
    flag = 2;
  }
 for (int i = 0; i < lim; i++) {
    cout << o[i] << e[i];
 }
 if(flag == 1){
   cout << o[oz-1];
 }
 else if (flag == 2) {
   cout << e[ez-1];
 }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  string co;
  cin >> co;
  string CO = "CODEFESTIVAL2016";
  int ans = 16;
  rep(i, 16) {
    if(CO.at(i) == co.at(i)) {
      ans--;
    }
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string ans="No";
  while (N>0) {
    if (N%10==9) {
      ans = "Yes";
      break;
    }
    N/=10;
  }
  cout << ans << endl;
}

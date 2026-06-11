#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int odd_cnt;
  for (int i; i < n; i++) {
    int a;
    cin >> a;
    if (a%2 == 1) {
      odd_cnt += 1;
    }
  }
  if (odd_cnt % 2 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
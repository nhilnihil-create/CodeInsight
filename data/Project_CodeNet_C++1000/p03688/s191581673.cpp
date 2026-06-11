#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> la(n);
  int upper = 0;
  int lower = n;
  for (int i = 0; i < n; ++i) {
    cin >> la[i];
    upper = max(upper, la[i]);
    lower = min(lower, la[i]);
  }
  if (upper-lower > 1) {
    cout << "No" << endl;
    return 0;
  }
  if (upper == lower) {
    if (upper*2 <= n) {
      cout << "Yes" << endl;
    }
    else if (upper+1 == n) {
      // 全部違う色の時
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
    return 0;
  }
  int c = upper;
  int m = n;
  for (int a: la) {
    if (a == lower) { 
      --c;
      --m;
    }
  }
  if (c <= 0 || c*2 > m) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}
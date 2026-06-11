#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int x = 1;
  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (x != 0) {
    x = a[x-1];
    if (x == 2) {
      count = i+1;
      break;
    }
    }
    else {
      x = a[x-1];
    }
  }
  if (count!=0) {
    cout << count << endl;
  }
  else {
    cout << -1 << endl;
  }
}
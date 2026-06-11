#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int x = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    x = a[x]-1;
    if (x == 1) {
      count = i+1;
      break;
    }
  }
  if (count !=0) {
    cout << count << endl;
  }
  else {
    cout << count-1 << endl;
  }
}
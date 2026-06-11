#include <bits/stdc++.h>
using namespace std;

int main() {
  int count5 = 0, count7 = 0;
  // int arr[3];
  for (int i = 0; i < 3; i++) {
    int t;
    cin >> t;
    if (t == 5) count5++;
    if (t == 7) count7++;
  }
  if (count5 == 2 && count7 == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int K, T;
  cin >> K >> T;
  vector<int> a(T);
  for (int i = 0; i < T; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  cout << max(a[0] - accumulate(a.begin() + 1, a.end(), 0) - 1, 0) << endl;
  return 0;
}
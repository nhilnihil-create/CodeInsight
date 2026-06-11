#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, T;
  cin >> K >> T;
  vector<int> A(T);
  for (int i = 0; i < T; i++) cin >> A.at(i);
  int mx = *max_element(A.begin(), A.end());
  int sum = accumulate(A.begin(), A.end(), 0);
  sum -= mx;
  mx--;
  int ans = mx - sum;
  if (ans < 0) ans = 0;
  cout << ans << "\n";
}
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  int64_t ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    if ((A.at(i) + ans) % B.at(i) != 0) {
      ans += B.at(i) - (A.at(i) + ans) % B.at(i);
    }
  }
  cout << ans << endl;
}
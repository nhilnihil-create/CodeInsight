#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;  
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  int ans = 0;
  int memo = 1;
  for (int i = 0; i < N - 1; i++) {
    if (A.at(i) == A.at(i + 1)) {
      memo++;
    }
    else {
      if (memo % 2 == 1) {
        ans++;
      }
      memo = 1;
    }
  }
  if (memo % 2 == 1) {
    ans++;
  } 
  cout << ans << endl;
}
     
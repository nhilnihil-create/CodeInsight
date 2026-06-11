#include<iostream>

using namespace std;

int main() {
  int K, S;
  cin >> K >> S;
  //cout << K << S << endl;
  int ans = 0;
  for (int i = 0; i <= K; ++i) {
    for (int j = K; j >= 0; --j) {
      int k = S - i - j;
      if (k < 0 || K < k) continue;
      //printf("%d %d %d\n", i, j, k);
      ans++;
    }
  }
  cout << ans << endl;
}
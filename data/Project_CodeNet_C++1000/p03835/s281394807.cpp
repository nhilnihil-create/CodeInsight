#include <bits/stdc++.h>
using namespace std;

int main() {
  int K,S; cin >> K >> S;
  
  long ans =0;
  for (int i =0; i<=K; i++) {
    for (int j =i; j<=K; j++) {
      int k = S - i - j;
      if (k < j || k > K) continue;
      if (i == j && j == k) {
        ans++; continue;
      } else if (i == j && i != k) {
        ans += 3; continue;
      } else if (j == k && i != j) {
        ans += 3; continue;
      } else {
        ans += 6;
      }
    }
  }
  cout << ans << endl;
}
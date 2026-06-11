#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, S;
  int count;
  cin >> K >> S;

  count = 0;
  for (int i = 0; i <= K; i++) {
    for (int j = 0; j <= K ; j++) {
      if (i+j <= S && S <= i+j+K) count++;
    }
  }
  cout << count;
}
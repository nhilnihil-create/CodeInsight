#include <bits/stdc++.h>
using namespace std;

long long int MOD = 1000000007;

int main() {
  int N;
  cin >> N;
  
  vector<bool> P(N + 1, false);
  for (int i = 2; i <= N; i++) {
    bool X = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) X = false;
    }
    if (X) P.at(i) = true;
  }
  
  long long int ans = 1;
  for (int i = 2; i <= N; i++) {
    if (P.at(i) == false) continue;
    long long int k = 0;
    for (int j = 2; j <= N; j++) {
      int t = j;
      while (t % i == 0) {
        k++;
        t /= i;
      }
    }
    ans = ans * (k + 1) % MOD;
  }
  
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, ans = 1;
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    ans *= i;
    ans %= 1000000007;
  }
  
  cout << ans << endl;
}
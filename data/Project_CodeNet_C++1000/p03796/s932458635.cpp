#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int64_t power = 1LL;
  for(int i = 1; i <= n; i++) {
    power *= i;
    power %= 1000000007;
  }
  cout << power;
}
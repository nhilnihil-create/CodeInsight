#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ll N;
  cin >> N;
  for (int i = sqrt(N); i > 0; --i) {
    if (N % i == 0) {
      N /= i;
      break;
    }
  }
  cout << static_cast<int>(log10(N)) + 1 << endl;
  return 0;
}

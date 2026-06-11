#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  long long power = 1;
  for (int i = 1; i <= N; ++i) {
    power *= (long long)i;
    power %= 1000000007;
  }
  cout << power << endl;

  return 0;
}

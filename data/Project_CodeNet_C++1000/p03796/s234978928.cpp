#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int64_t power = 1;
  int64_t d = pow(10, 9) + 7;
  for (int i = 1; i <= N; i++) {
    power *= i;
    while (power >= d) {
      power %= d;
    }
  }
  cout << power << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int64_t kaijo(int n) {
  if (n == 0) {
    return 1;
  }
  int64_t tmp = n * kaijo(n - 1);
  if (tmp > (1000000000 + 7)) {
    return tmp % (1000000000 + 7);
  }
  else {
    return tmp;
  }
}
    
int main() {
  int n;
  cin >> n;
  int64_t result = kaijo(n);
  cout << result << endl;
}

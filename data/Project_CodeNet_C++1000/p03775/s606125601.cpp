#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  
  int digit = log10(N) + 1;
  for (int i = 2; i <= sqrt(N); i++) {
    if (N % i == 0) {
      int dd = log10(N / i) + 1;
      digit = min(digit, dd);
    }
  }
  
  cout << digit << endl;
}

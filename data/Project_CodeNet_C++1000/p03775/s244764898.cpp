#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  for (long long i = sqrt(N); i > 0; i--) {
    if (N%i == 0) {
      int count = 1;
      long long n = N/i;
      while(n >= 10) {
        n /= 10;
        count++;
      }
      cout << count << endl;
      break;
    }
  }
}
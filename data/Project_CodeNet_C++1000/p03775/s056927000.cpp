#include<bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  
  int ans = 10;
  for (long a = 1; a <= sqrt(N); a++) {
    if (N % a == 0) {
      int ord = 0;
      long b = N / a;
      while (b > 0) {
        b /= 10;
        ord++;
      }
      ans = min(ans, ord);
    }
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int f(long long a, long long b) {
    int d_a = 1;
    while (a / 10 != 0){
        d_a++;
        a /= 10;
    }

    int d_b = 1;
    while (b / 10 != 0){
        d_b++;
        b /= 10;
    }

    return max(d_a, d_b);
}



int main() {
  long long n;
  cin >> n;
  
  int ans = 1000000;
  for (int i = 1; i < 100010; i++) {
    if (n % i == 0) {
      ans = min(ans, f(i, n/i));
    }
  }
  cout << ans << endl;
}
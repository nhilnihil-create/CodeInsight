#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int keta(long x) {
  return x ? 1 + keta(x/10): 0;
}

int main() {
  long n;
  cin >> n;
  int ans = 100;
  for (long i = 1; i * i <= n; i++) {
    if (n % i != 0) continue;
    int a = keta(i);
    int b = keta(n / i);
    ans = min(ans, max(a, b));
  }
  cout << ans << endl;
}
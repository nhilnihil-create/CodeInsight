#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long a = n;
  long long b = m;
  if (abs(n-m) <= 1){
  if (n == m) {
    for (int i = n; i > 1; i--) {
      a = a*(i-1)%1000000007;
    }
    cout << a*a%1000000007*2%1000000007 << endl;
  }
  else {
    for (int i = n; i > 1; i--) {
      a = a*(i-1)%1000000007;
    }
    for (int i = m; i > 1; i--) {
      b = b*(i-1)%1000000007;
    }
    cout << a*b%1000000007 << endl;
  }
  }
  else {
    cout << 0 << endl;
  }
}
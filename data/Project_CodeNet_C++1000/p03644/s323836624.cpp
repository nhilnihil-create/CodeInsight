#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,n=1,m=0,p;
  cin >> N;
  for (int i = 2; i <= N; i++) {
    p = 0;
    for (int j = i; !(j%2); j /= 2, p++);
    if (p > m) {
      m = p;
      n = i;
    }
  }
  cout << n;
}
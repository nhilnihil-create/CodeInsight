#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A, B, C, D;
  cin >> A >> B >> C >> D;
  long long R = min(B, D), L = max(A, C);
  cout << max(0LL, R - L) << endl;
}
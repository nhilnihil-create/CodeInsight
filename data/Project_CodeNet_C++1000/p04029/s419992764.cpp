#include <bits/stdc++.h>
using namespace std;
int sum1toN(const int n) { return n * (n + 1) / 2; }
int main() {
  int N;
  cin >> N;
  cout << sum1toN(N) << endl;
  getchar();
}
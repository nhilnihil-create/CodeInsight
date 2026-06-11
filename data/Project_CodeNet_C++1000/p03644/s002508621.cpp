#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < 7; i++) {
    if (pow(2, i + 1) > N) {
      cout << pow(2, i) << endl;
      return 0;
    }
  }
  return 0;
}
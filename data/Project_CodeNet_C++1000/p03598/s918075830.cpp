#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<int> xs(n);
  for (int &x : xs) {
    cin >> x;
  }

  int result = 0;
  for (const int &x : xs) {
    result += min(x, k - x) * 2;
  }

  cout << result << endl;
  return 0;
}
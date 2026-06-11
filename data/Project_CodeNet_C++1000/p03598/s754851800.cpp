#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, sum;
  cin >> n >> k;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
  }

  for (int i = 0; i < n; i++) {
    sum += min(vec[i], k - vec[i]) * 2;
  }

  cout << sum << endl;
}
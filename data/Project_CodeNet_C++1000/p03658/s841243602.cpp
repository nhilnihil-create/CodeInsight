#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int s = 0;
  for (int i = 0; i < k; i++) {
    s += v.at(i);
  }
  cout << s << endl;
}
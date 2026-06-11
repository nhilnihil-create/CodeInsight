#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  for (int i = 0; i < n; ++i) cin >> l[i];
  sort(l.begin(), l.end());
  int sum = 0;
  for (int i = n - k; i < n; ++i) sum += l[i];
  cout << sum << endl;
}

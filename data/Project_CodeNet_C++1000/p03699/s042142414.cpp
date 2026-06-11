#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;

  sort(vec.begin(), vec.end());

  int vsum = accumulate(vec.begin(), vec.end(), 0);

  int vmin = vsum;
  for (int i = 0; i < n; ++i) {
    if (vec[i] % 10 == 0)
      continue;
    vmin = min(vmin, vec[i]);
  }

  cout << (vsum % 10 == 0 ? vsum - vmin : vsum) << endl;
}

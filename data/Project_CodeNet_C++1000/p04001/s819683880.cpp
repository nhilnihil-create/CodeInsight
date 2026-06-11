#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int64_t num = 1 << (n - 1);
  int64_t sum = 0;
  for (int64_t i = 0; i < num; ++i) {
    vector<int> part;
    part.push_back(0);
    for (int j = 0; j < n - 1; ++j) {
      if (i & (1 << j)) {
        part.push_back(j + 1);
      }
    }
    part.push_back(n);
    int64_t tmpSum = 0;
    for (int j = 0; j < part.size() - 1; ++j) {
      tmpSum += stoull(s.substr(part.at(j), part.at(j + 1) - part.at(j)));
    }
    sum += tmpSum;
  }

  cout << sum << endl;
}

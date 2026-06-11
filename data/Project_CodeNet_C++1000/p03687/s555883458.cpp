#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;

  vector<int> results;
  int min_count = 100;
  rep(i, 26) {
    int count = 0;
    results.resize(0);
    rep(j, s.size()) {
      if(s[j] - 'a' == i) {
        results.push_back(count);
        count = 0;
      } else {
        count++;
      }
    }
    results.push_back(count);
    sort(results.begin(), results.end(), greater<int>());
    min_count = min(min_count, results[0]);
  }
  cout << min_count << endl;
  return 0;
}

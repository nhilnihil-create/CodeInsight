#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mp[a]++;
  }
  vector<pair<int, int>> vec;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    int len = it->first;
    int cnt = it->second;
    if (cnt >= 2) {
      vec.push_back(make_pair(len, cnt));
    }
  }
  sort(vec.begin(), vec.end(), greater<pair<int, int>>());

  if (vec.size() == 0) {
    cout << 0 << endl;
    return 0;
  }

  long long len = vec[0].first;
  long long cnt = vec[0].second;

  if (cnt >= 4) {
    cout << len * len << endl;
  } else if (vec.size() < 2) {
    cout << 0 << endl;
  } else {
    cout << len * vec[1].first << endl;
  }

  return 0;
}
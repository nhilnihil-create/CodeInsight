#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];

  map<int, int> a_map;
  for (int i = 0; i < N; i++) {
    a_map[a[i] - 1]++;
    a_map[a[i]]++;
    a_map[a[i] + 1]++;
  }

  int max_count = 0;
  for (auto itr = a_map.begin(); itr != a_map.end(); itr++) {
    max_count = max(max_count, itr->second);
  }
  cout << max_count << endl;
}

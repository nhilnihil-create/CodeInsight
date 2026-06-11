#include <bits/stdc++.h>
using namespace std;

int h, w;
priority_queue<int> pq;
vector<int> cnt(26, 0);

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (auto c : s) ++cnt[c - 'a'];
  }
  for (int i = 0; i < 26; ++i) pq.push(cnt[i]);
  vector<int> v;
  for (int i = 0; i < (h + 1) / 2; ++i)
    for (int j = 0; j < (w + 1) / 2; ++j) {
      int now = 4;
      if ((h & 1) && i == h / 2) now >>= 1;
      if ((w & 1) && j == w / 2) now >>= 1;
      v.push_back(now);
    }
  sort(v.begin(), v.end(), greater<int>());
  for (auto p : v) {
    if (p > pq.top()) {
      cout << "No" << endl;
      return 0;
    }
    p = pq.top() - p;
    pq.pop();
    pq.push(p);
  }
  cout << "Yes" << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n];
  for (int i=0; i<n; i++) cin>>a[i];
  map<int, vector<int>> m;
  for (int i=0; i<n; i++) {
    m[a[i]].push_back(i);
  }
  vector<pair<int, vector<int>>> v;
  for (auto i: m) {
    v.emplace_back(i.first, i.second);
  }
  reverse(v.begin(), v.end());
  int idx = 0;
  set<int> numbers;
  long long cnt[n];
  for (int i=0;i<n; i++) cnt[i] = 0;
  while (idx < v.size()) {
    for (int i: v[idx].second) {
      numbers.insert(i);
    }
    long long diff;
    if (idx != v.size() - 1) {
      diff = v[idx].first - v[idx+1].first;
    } else {
      diff = v[idx].first;
    }
    cnt[*numbers.begin()] += diff * numbers.size();
    ++idx;
  }
  for (long long i: cnt) {
    cout<<i<<endl;
  }
}
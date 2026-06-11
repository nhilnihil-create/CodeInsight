#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int heightest = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > a[heightest]) {
      heightest = i;
    }
  }
  vector<int> stack;
  for (int i = heightest; i >= 0; i--) {
    while (stack.size() && a[stack.back()] <= a[i]) stack.pop_back();
    stack.push_back(i);
  }

  map<int,long long> cnt;
  for (auto i : a) cnt[i]++;
  vector<long long> ans(n);

  for (int i = 1; i < (int) stack.size(); i++) {
    int high = a[stack[i - 1]];
    int low = a[stack[i]];
    auto it = cnt.upper_bound(low);
    while (it != cnt.end()) {
      ans[stack[i - 1]] += it->second * (it->first - low);
      cnt[low] += it->second;
      it++;
    }
    cnt.erase(cnt.upper_bound(low), cnt.end());
  }
  for (auto i : cnt) {
    ans[0] += i.second * i.first;
  }

  for (auto i : ans) {
    cout << i << '\n';
  }
  return 0;
}


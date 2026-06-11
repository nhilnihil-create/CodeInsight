#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    mp[a.at(i)]++;
  }
  
  sort(a.begin(), a.end());
  
  if (mp.size() >= 3 || a.back() - a.front() >= 2) {
    cout << "No\n";
  }
  else if (mp.size() == 1) {
    int x = a.front();
    if (x == n - 1 || n / 2 >= x) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }
  else {
    int x = a.front(), y = a.back();
    if (mp[x] < y && (y - mp[x]) <= mp[y] / 2) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }
}
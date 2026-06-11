#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

void OutputNo() {
  cout << "No\n";
  exit(0);
}

void OutputYes() {
  cout << "Yes\n";
  exit(0);
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  map<int, int> mp;
  for (int x : a) mp[x]++;
  if (mp.size() > 2) {
    OutputNo();
  }
  if (mp.size() == 1) {
    int k = a[0];
    if (n == k + 1) OutputYes();
    if (n >= 2 * k) OutputYes();
    OutputNo();
  }

  int k = mp.begin()->first;
  int l = mp[k];
  if (!mp.count(k + 1)) OutputNo();
  int r = mp[k + 1];
  if (l == k && r >= 2) OutputYes();
  if (l < k) {
    if (n >= k + 1 + k + 1 - l) OutputYes();
  }

  OutputNo();

  return 0;
}

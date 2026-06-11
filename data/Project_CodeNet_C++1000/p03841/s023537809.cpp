#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
 
using namespace std;
 
typedef long long ll;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif  
  int n;
  cin >> n;
  vector <int> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  vector <int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&] (int i, int j) {
    return x[i] < x[j];
  });
  vector <int> ans;
  vector <int> used(n);
  vector <int> have(n);
  for (int id : p) {
 
    for (int i : p) {
      while (ans.size() + 1 < x[id] && (!used[i] && have[i] < i)) {
        ++have[i];
        ans.push_back(i + 1);
      }
    }
    for (int i : p) {
      while (ans.size() + 1 < x[id] && (used[i] && have[i] != n)) {
        ++have[i];
        ans.push_back(i + 1);
      }
    }
 
    ans.push_back(id + 1);
    ++have[id];
    used[id] = 1;
    if (ans.size() != x[id] || have[id] != id + 1) {
      cout << "No\n";
      return 0;
    }
  } 
  for (int i = 0; i < n; ++i) {
    while (have[i] != n) {
      ans.push_back(i + 1);
      ++have[i];
    }
  }
  cout << "Yes\n";
  for (int x : ans) cout << x << ' ';
}

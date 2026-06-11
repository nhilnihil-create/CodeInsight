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

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    cin >> a[i][j];
    a[i][j]--;
  }
  vector<int> at(n);
  vector<bool> alive(m, true);
  int result = n;
  for (int step = 0; step < m; ++step) {
    vector<int> count(m);
    for (int i = 0; i < n; ++i) count[a[i][at[i]]]++;
    int bestI = 0;
    for (int i = 0; i < m; ++i) if (count[i] > count[bestI]) bestI = i;
    result = min(result, count[bestI]);
    alive[bestI] = false;
    for (int i = 0; i < n; ++i) {
      int j = at[i];
      while (j < m && !alive[a[i][j]]) ++j;
      at[i] = j;
    }
  }
  cout << result << endl;
  return 0;
}

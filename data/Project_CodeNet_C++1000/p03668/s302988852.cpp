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

int Grundy(int v, int from, const vector<vector<int>>& g) {
  int result = 0;
  for (int x : g[v]) if (x != from) result ^= 1 + Grundy(x, v, g);
  return result;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  if (Grundy(0, -1, g) > 0) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }
  return 0;
}

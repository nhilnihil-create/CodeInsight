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
typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{
  int n, m;
  cin >> n >> m;
  vi cnt(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cnt[a]++;
    cnt[b]++;
  }
  for (int i = 0; i < n; ++i) {
    if (cnt[i] % 2) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}

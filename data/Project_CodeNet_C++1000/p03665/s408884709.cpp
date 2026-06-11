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
  int n, p;
  cin >> n >> p;
  vector<ll> ans(2);
  ans[0] = 1;

  for (int i = 0; i < n; ++i) {
    vector<ll> next = ans;
    int a;
    cin >> a;
    a %= 2;
    for (int j = 0; j < 2; ++j) next[j ^ a] += ans[j];
    ans = next;
  }

  cout << ans[p] << endl;

  return 0;
}

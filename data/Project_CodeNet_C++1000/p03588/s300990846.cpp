#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > vec(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    vec[i].first = a, vec[i].second = b;
  }
  sort(vec.begin(), vec.end());
  cout << vec[n - 1].first + vec[n - 1].second << endl;
  return 0;
}
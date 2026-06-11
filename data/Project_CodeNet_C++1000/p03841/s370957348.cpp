#define _USE_MATH_DEFINES
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 30;
const int MOD = 1e9 + 7;

void print(vector<int>& a) {
  for (auto& it : a) {
    cout << it << " ";
  }
  cout << endl;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<ii> x(n);
  vector<int> ret(n * n);
  vector<bool> fixed(n * n);
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    --v;
    x[i] = {v, i + 1};
    ret[v] = i + 1;
    fixed[v] = true;
  }
  sort(x.begin(), x.end());
  bool found = false;
  for (int i = 0; i < n; ++i) {
    int L = x[i].second - 1, R = n - 1 - L, j;
    vector<int> homeless;
    for (j = 0; L && j < x[i].first; ++j) {
      if (ret[j] == 0) {
        ret[j] = x[i].second;
        fixed[j] = true;
        --L;
      } else if (!fixed[j]) {
        homeless.push_back(ret[j]);
        ret[j] = x[i].second;
        fixed[j] = true;
        --L;
      }
    }
    if (L) {
      found = true;
      break;
    }
    for (; homeless.size() && j < x[i].first; ++j) {
      if (ret[j] == 0) {
        ret[j] = homeless.back();
        homeless.pop_back();
      }
    }
    // print(ret);
    for (j = x[i].first + 1; (R || homeless.size()) && j < n * n; ++j) {
      if (ret[j]) continue;
      if (R) {
        ret[j] = x[i].second;
        --R;
      } else {
        ret[j] = homeless.back();
        homeless.pop_back();
      }
    }
    if (R || homeless.size()) {
      found = true;
      break;
    }
    // print(ret);
    // trace("==");
  }
  if (found) {
    puts("No");
  } else {
    puts("Yes");
    for (int i = 0; i < n * n; ++i) {
      printf("%d%c", ret[i], " \n"[i + 1 == n * n]);
    }
  }
  return 0;
}

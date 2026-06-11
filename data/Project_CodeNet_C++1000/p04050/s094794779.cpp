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

int main() {
  int n, m, cnt = 0;
  scanf("%d%d", &n, &m);
  vector<int> len(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &len[i]);
    if (len[i] % 2) ++cnt;
  }
  if (n == 1) {
    printf("1\n1\n1\n");
    return 0;
  }
  if (m == 1) {
    printf("%d\n", len[0]);
    printf("%d\n%d %d\n", 2, len[0] - 1, 1);
    return 0;
  }
  if (cnt > 2) {
    puts("Impossible");
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    if (len[i] % 2 && i != 0 && i != m - 1) {
      if (len[0] % 2 == 0) {
        swap(len[0], len[i]);
      } else {
        swap(len[m - 1], len[i]);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    printf("%d%c", len[i], " \n"[i + 1 == m]);
  }
  vector<int> ret;
  if (len[0] - 1 > 0) ret.push_back(len[0] - 1);
  for (int i = 1; i < m - 1; ++i) ret.push_back(len[i]);
  ret.push_back(len[m - 1] + 1);
  printf("%d\n", (int)ret.size());
  for (int i = 0; i < ret.size(); ++i) {
    printf("%d%c", ret[i], " \n"[i + 1 == ret.size()]);
  }
  return 0;
}

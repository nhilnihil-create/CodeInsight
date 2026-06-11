#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

const int MAXN = 105000;

int n;
int x[MAXN];
int go[MAXN];
int len;
int qn;
vector < pair<int, int> > q[MAXN];
int ans[MAXN];
int p[MAXN][20];

int getNthParent(int v, int x) {
  for (int i = 19; i >= 0; i--) {
    while (x >= (1 << i)) {
      v = p[v][i];
      x -= (1 << i);
    }
  }
  return v;
}

int main() { 

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  scanf("%d", &len);
  scanf("%d", &qn);
  for (int i = 0; i < qn; i++) {
    int from, to;
    scanf("%d %d", &from, &to);
    from--; to--;
    if (from > to) {
      swap(from, to);
    }
    q[from].push_back({to, i});
  }

  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      go[i] = i;
      continue;
    }
    int l = i + 1, r = n - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (x[mid] - x[i] <= len) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    go[i] = l;
  }

  for (int i = n - 1; i >= 0; i--) {
    p[i][0] = go[i];
    for (int j = 1; j < 20; j++) {
      p[i][j] = p[p[i][j - 1]][j - 1];
    }
  }

  for (int i = 0; i < n; i++) {
    for (auto curQ : q[i]) {
      int to = curQ.first, idx = curQ.second;
      int l = 0, r = n;
      while (l < r) {
        int mid = (l + r) / 2;
        int par = getNthParent(i, mid);
        if (par >= to) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      ans[idx] = l;
    }
  }

  for (int i = 0; i < qn; i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}

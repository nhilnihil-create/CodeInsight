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

int n, m;
int cnt[MAXN];

int main() { 

  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    cnt[a]++; cnt[b]++;
  }

  for (int i = 1; i <= n; i++) {
    if (cnt[i] & 1) {
      puts("NO");
      return 0;
    }
  }

  puts("YES");

  return 0;
}

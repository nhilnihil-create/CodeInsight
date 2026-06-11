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

const int MAXN = 20050;

int n;
int p[MAXN], pr[MAXN];
int a[MAXN], b[MAXN];

int main() { 

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    pr[p[i] - 1] = i + 1;
  }

  for (int i = 0; i < n; i++) {
    a[i] = 30000 * (i + 1);
  }
  for (int i = 0; i < n; i++) {
    b[i] = (n - 1 - i) * 30000 + pr[i];
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    printf("%d ", b[i]);
  }
  cout << endl;

  return 0;
}

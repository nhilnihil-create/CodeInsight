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

const int MAXN = 2 * 105000;

class Fenwick {
private:
  vector <long long> f;
public:
  void init(int n) {
    f.assign(n, 0);
  }
  void update(int pos, int delta) {
    for (; pos < sz(f); pos = (pos | (pos + 1))) {
      f[pos] += delta;
    }
  }
  long long sum(int pos) {
    long long res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
      res += f[pos];
    }
    return res;
  }
  long long sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};

int n, k;
int a[MAXN];
vector< pair<long long, int> > v;

int main() {

  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] -= k;
  }

  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    v.push_back({sum, i});
  }
  sort(all(v));

  Fenwick f;
  f.init(n);

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].first >= 0) {
      ans++;
    }
    ans += f.sum(0, v[i].second);
    f.update(v[i].second, 1);
  }

  cout << ans << endl;

  return 0;
}

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
int a[MAXN];
long long stupid = 0;
vector<int> startHere[MAXN], endHere[MAXN];
vector<int> startHere2[MAXN], endHere2[MAXN];

int jump(int from, int to) {
  if (to > from) {
    return to - from;
  }
  return m - from + to;
}

int main() { 

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int i = 1; i < n; i++) {
    stupid += jump(a[i - 1], a[i]);
  }

  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      startHere[a[i - 1]].push_back(i);
      endHere[a[i]].push_back(i);
    } else {
      startHere2[a[i - 1]].push_back(i);
      endHere2[a[i]].push_back(i);
    }
  }

  long long ans = stupid;
  long long rem = 0, add = 0;
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for (int x = 1; x <= m; x++) {
    for (int i : endHere2[x]) {
      rem += jump(a[i - 1], a[i]);
      add += 1 + a[i];
      cnt1++;
    }
  }

  // cerr << stupid << endl;
  for (int x = 1; x <= m; x++) {
    // cerr << x << " " << stupid - rem + add - 1ll * x * (cnt1 + cnt2 + cnt3) << endl;
    // cerr << rem << " " << add << " " << cnt1 << " " << cnt2 << " " << cnt3 << endl;
    ans = min(ans, stupid - rem + add - 1ll * x * (cnt1 + cnt2 + cnt3));

    for (int i : startHere2[x]) {
      rem += jump(a[i - 1], a[i]);
      add += 1 + m + a[i];
      cnt2++;
    }
    for (int i : endHere[x]) {
      rem -= jump(a[i - 1], a[i]);
      add -= 1 + a[i];
      cnt3--;
    }
    for (int i : endHere2[x]) {
      rem -= jump(a[i - 1], a[i]);
      add -= 1 + a[i];
      cnt1--;
    }
    for (int i : startHere[x]) {
      rem += jump(a[i - 1], a[i]);
      add += 1 + a[i];
      cnt3++;
    }
  }

  cout << ans << endl;

  return 0;
}

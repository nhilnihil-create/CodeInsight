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

int n;
string s;
set <int> st[26];
int r[MAXN][26];

int main() {

  getline(cin, s);
  n = sz(s);
  for (int i = 0; i < sz(s); i++) {
    st[s[i] - 'a'].insert(i);
  }

  for (int i = 0; i < 26; i++) {
    if (sz(st[i]) == 0) {
      cout << (char) ('a' + i) << endl;
      return 0;
    }
    auto lst = st[i].end();
    lst--;
    r[1][i] = *lst;
  }

  string ans = "";
  int ansLen = 0;
  int pos = -1;
  for (int i = 2; i <= n; i++) {
    int mn = n;
    for (int j = 0; j < 26; j++) {
      mn = min(mn, r[i - 1][j]);
    }
    for (int j = 0; j < 26; j++) {
      auto it = st[j].lower_bound(mn);
      if (it != st[j].begin()) {
        it--;
        r[i][j] = *it;
      } else {
        ansLen = i;
        pos = *st[j].begin();
        ans.append(1, 'a' + j);
        break;
      }
    }
    if (ansLen != 0) {
      break;
    }
  }

  for (int i = 0; i < ansLen - 1; i++) {
    for (int j = 0; j < 26; j++) {
      if (r[ansLen - 1 - i][j] > pos) {
        continue;
      }
      ans.append(1, 'a' + j);
      auto it = st[j].upper_bound(pos);
      if (it != st[j].end()) {
        pos = *it;
      }
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
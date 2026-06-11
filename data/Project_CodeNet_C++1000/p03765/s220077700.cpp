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

string s, t;
int cntS[MAXN], cntT[MAXN];

int main() { 

  getline(cin, s);
  getline(cin, t);

  for (int i = 0; i < sz(s); i++) {
    if (s[i] == 'A') {
      cntS[i]++;
    }
    if (i > 0) {
      cntS[i] += cntS[i - 1];
    }
  }

  for (int i = 0; i < sz(t); i++) {
    if (t[i] == 'A') {
      cntT[i]++;
    }
    if (i > 0) {
      cntT[i] += cntT[i - 1];
    }
  }

  int qn;
  scanf("%d", &qn);
  while (qn--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    a--; b--; c--; d--;

    int sc = cntS[b];
    if (a > 0) {
      sc -= cntS[a - 1];
    }
    sc = (b - a + 1 - sc) + sc * 2;

    int tc = cntT[d];
    if (c > 0) {
      tc -= cntT[c - 1];
    }
    tc = (d - c + 1 - tc) + tc * 2;

    if (abs(tc - sc) % 3 == 0) {
      puts("YES");
    } else {
      puts("NO");
    }
  }


  return 0;
}

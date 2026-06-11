#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define pb push_back
#define mp make_pair

#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int N = (int) 1e6 + 7;
const int MOD = (int) 1e9 + 7;

bool ask(int n) {
  cout << "? " << n << endl;
  string ch;
  cin >> ch;
  return ch == "Y";
}

bool ask_st(string s) {
  cout << "? " << s << endl;
  string ch;
  cin >> ch;
  return ch == "Y";
}

int main() {
  #ifdef LOCAL
  freopen("in.txt", "r", stdin);
  #endif

  int len = 1;
  bool flag = 0;
  for (long long i = 10; i <= 10000000000ll; i = i * 10) {
    if (!ask(i)) {
      flag = 1;
      break;
    }
    len++;
  }
  if (!flag) {
    for (long long i = 1; i <= 10000000000ll; i = i * 10) {
      if (ask(i + 1)) {
        cout << "! " << i << endl;
        return 0;
      }
    }
  } else {
    string prefix = "";
    for (int i = 1; i <= len; i++) {
      int l = (i == 1), r = 9;
      int pos = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        string cur = prefix;
        cur += char(mid + '0');
        for (int j = i + 1; j <= len + 1; j++)
          cur += "9";
        if (ask_st(cur)) {
          pos = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      //assert(pos >= 0);
      prefix += char(pos + '0');
    }
    cout << "! " << prefix << endl;
  }
  return 0;
}
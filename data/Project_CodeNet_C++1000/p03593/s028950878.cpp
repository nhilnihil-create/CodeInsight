#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef long long ll;

int main() {
  int h, w;
  cin >> h >> w;

  int table[26] = {0};
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, s.length()) {
      table[s[j]-'a']++;
    }
  }
  if (h%2 == 0 && w%2 == 0) {
    rep(i, 26) {
      if ( table[i] % 4 != 0) {
        cout << "No" << endl;
        return 0;
      }
    }
  } else if (h%2 == 1 && w%2 == 1) {
    int cnt1 = 0, cnt2 = 0;
    rep(i, 26) {
      if (table[i]%4 == 1) { cnt1++; }
      if (table[i]%4 == 2) { cnt2++; }
      if (table[i]%4 == 3) {
        cnt1++;
        cnt2++;
      }
      if (cnt1 > 1 || cnt2 > (w+h-2)/2) {
        cout << "No" << endl;
        return 0;
      }
    }
  } else {
    int cnt2 = 0;
    rep(i, 26) {
      if (table[i]%4 == 1) {
        cout << "No" << endl;
        return 0;
      }
      if (table[i]%4 == 2) { cnt2++; }
      if (table[i]%4 == 3) {
        cout << "No" << endl;
        return 0;
      }
      if ( (h&1 && cnt2 > w/2) || (w&1 && cnt2 > h/2) ) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;

  return 0;
}
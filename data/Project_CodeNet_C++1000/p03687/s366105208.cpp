#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  vector<char> a(200, 0);
  for(int i = 1; i < n - 1; i++) {
    a[s[i]]++;
  }
  int maxi = *max_element(a.begin(), a.end());
  // cout << maxi << endl;
  if(maxi == 1) {
    bool ok = true;
    char tmp = s[0];
    for(int j = 0; j < n; j++) {
      if(s[j] != tmp) {
        ok = false;
        break;
      }
    }
    if(ok) {
      cout << 0 << endl;
    } else {
      cout << n / 2 << endl;
    }
    return 0;
  }
  string t;
  int ans = 1001001001;
  string re = s;

  for(int i = 'a'; i <= 'z'; i++) {
    int cnt = 0;
    s = re;
    while(1) {
      bool ok = true;
      char tmp = s[0];
      n = s.length();
      for(int j = 0; j < n; j++) {
        if(s[j] != tmp) {
          ok = false;
          break;
        }
      }
      if(ok) {
        // cout << cnt << endl;
        // cout << s << endl;
        ans = min(ans, cnt);
        break;
      }
      for(int j = 0; j < n - 1; j++) {
        if(s[j] == i) {
          t += s[j];
        } else if(s[j + 1] == i) {
          t += s[j + 1];
        } else {
          t += s[j];
        }
      }
      s = t;
      t.clear();
      cnt++;
    }
  }
  cout << ans << endl;
  return 0;
}
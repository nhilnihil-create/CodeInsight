// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

vector<string> S {
  "dream",
  "dreamer",
  "eraser",
  "erase",
};

int main() {
  string t; cin >> t;
  reverse(t.begin(), t.end());
  for (auto&& s: S) reverse(s.begin(), s.end());
  while (t != "") {
    bool ok = false;
    for (auto &&s: S) {
      if (t.find(s) == 0) {
        t = t.substr(s.size());
        ok = true;
        break;
      }
    }
    
    if (!ok) {
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
  return 0;
}

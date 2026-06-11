#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i<b; i++)
int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    rep(i, 0, n) {
      string s2 = s.substr(i, n - i);
      string t2 = t.substr(0, n - i);
      if(s2 != t2) continue;
      cout << n + i << endl;
      return 0;
    }
    cout << n * 2 << endl;
}

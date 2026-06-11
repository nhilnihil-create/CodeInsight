#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  string s1 = "maerd";
  string s2 = "remaerd";
  string s3 = "esare";
  string s4 = "resare";
  bool fail_flag = false;
  for (int i = 0; i < S.length(); i++) {
    if (S.substr(i, s1.length()) == s1) {
      i += s1.length() - 1;
    } else if (S.substr(i, s2.length()) == s2) {
      i += s2.length() - 1;
    } else if (S.substr(i, s3.length()) == s3) {
      i += s3.length() - 1;
    } else if (S.substr(i, s4.length()) == s4) {
      i += s4.length() - 1;
    } else {
      fail_flag = true;
      break;
    }
  }

  string ans = (fail_flag) ? "NO" : "YES";
  cout << ans << endl;
  return 0;
}
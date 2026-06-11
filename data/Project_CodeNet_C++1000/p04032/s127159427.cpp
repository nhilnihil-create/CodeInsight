#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
const int IINF = 1e9;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

#define dump(x) cout << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl

template <typename T>
void dumpvec(vector<T> vec) {
  for (T cnt : vec) {
    cout << cnt << ", ";
  }
  cout << endl;
}

void chmin(ll &a, ll b) {
  if (a > b) {
    a = b;
  }
}
void chmax(ll &a, ll b) {
  if (a < b) {
    a = b;
  }
}

vector<string> split(string s, string delimiter) {
  int first = 0;
  int last = s.find_first_of(delimiter);
  vector<string> result;

  while (first < s.size()) {
    string sub = s.substr(first, last - first);
    result.push_back(sub);
    first = last + 1;
    last = s.find_first_of(delimiter, first);

    if (last == string::npos) {
      last = s.size();
    }
  }

  return result;
}

string join(vector<string> strings, string delimiter) {
  string result = "";
  for (int i = 0; i < strings.size(); i++) {
    if (result != "") result += delimiter;
    result += strings[i];
  }
  return result;
}

class Solution {
 public:
  void solve() {
    string s;
    cin >> s;

    // 50%を超えるには
    // 1. XYXがあるか. abababa -> 結局abaがあれば対象
    // 2. XXがあるか abaabba -> 結局aaがあれば対象
    // をみつければいい
    for (char c = 'a'; c <= 'z'; c++) {
      for (int i = 0; i < s.length() - 1; i++) {
        // 連続して同じcharなら50%超え
        if (s[i] == c && s[i + 1] == c) {
          cout << (i + 1) << " " << i + 2 << endl;
          return;
        }
      }
      for (int i = 0; i < s.length() - 2; i++) {
        // 一つ飛びに同じcharなら50%超え
        if (s[i] == c && s[i + 2] == c) {
          cout << i + 1 << " " << i + 3 << endl;
          return;
        }
      }
    }
    cout << -1 << " " << -1 << endl;
  }
};

int main() { Solution().solve(); }
#include <algorithm>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  deque<char> q;
  rep(i, s.size()) {
    if (s[i] != 'B') {
      q.push_back(s[i]);
    } else {
      if (!q.empty()) {
        q.pop_back();
      }
    }
  }
  while (!q.empty()) {
    cout << q.front();
    q.pop_front();
  }
  return 0;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  map<char, int> mp;
  rep(i, h) rep(i, w) {
    char c;
    cin >> c;
    mp[c]++;
  }
  if (h%2 && w%2) {
    for (auto& e : mp) {
      if (e.second%2) {
        e.second--;
        break;
      }
    }
  }
  int cnt = 0;
  for (auto& e : mp) {
    cnt += e.second/4;
    e.second %= 4;
  }
  if (cnt < (h/2*2)*(w/2*2)/4) {
    cout << "No" << endl;
    return 0;
  }
  for (auto& e : mp) {
    if (e.second%2) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
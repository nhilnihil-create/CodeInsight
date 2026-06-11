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
  string s;
  cin >> s;
  set<char> exists;
  for (int i = 0; i < s.size(); i++) {
    exists.insert(s[i]);
  }
  for (char c = 'a'; c <= 'z'; c++) {
    if (exists.find(c) == exists.end()) {
      cout << c << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}
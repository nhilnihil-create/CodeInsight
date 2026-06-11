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
  deque<char> q;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'B') {
      if (!q.empty()) q.pop_back();
    } else {
      q.push_back(s[i]);
    }
  }
  while (!q.empty()) {
    cout << q.front();
    q.pop_front();
  }
  cout << endl;
  return 0;
}
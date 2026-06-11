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
  string s_a, s_b, s_c;
  cin >> s_a >> s_b >> s_c;
  map<char, string> m = {{'a', s_a}, {'b', s_b}, {'c', s_c}};
  int i_a = 0, i_b = 0, i_c = 0;
  map<int, int> i = {{'a', i_a}, {'b', i_b}, {'c', i_c}};
  queue<char> q;
  q.push('a');
  while (!q.empty()) {
    char c = q.front();
    q.pop();
    if (i[c] == m[c].length()) {
      cout << (char)toupper(c) << endl;
      return 0;
    }
    char next_c = m[c][i[c]];
    i[c]++;
    q.push(next_c);
  }
  return 0;
}
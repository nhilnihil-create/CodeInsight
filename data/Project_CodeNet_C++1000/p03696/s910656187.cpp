// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

typedef pair<int, int> P;
int main() {
  int n; cin >> n;
  string s; cin >> s;
  list<char> C;
  for (auto &&c: s) C.push_back(c);
  int depth = 0;
  int min_ = 1000000;
  for (auto &&c: s) {
    if (c == '(') depth++;
    else depth--;
    min_ = min(min_, depth);
  }
  while (min_++ < 0) C.push_front('(');
  depth = 0;
  for (auto &&c: C) {
    if (c == '(') depth++;
    else depth--;
  }
  while (depth-- > 0) C.push_back(')');
  for (auto&&c: C) cout << c;
  cout << endl;
  return 0;
}

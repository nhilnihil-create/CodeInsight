#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string sa, sb, sc;
  cin >> sa >> sb >> sc;
  int ai = 0, bi = 0, ci = 0;
  char turn = 'a';
  while (1) {
    if (turn == 'a') {
      if (ai == sa.size()) break;
      turn = sa[ai++];
    }
    else if (turn == 'b') {
      if (bi == sb.size()) break;
      turn = sb[bi++];
    }
    else {
      if (ci == sc.size()) break;
      turn = sc[ci++];
    }
  }
  char win = turn + 'A' - 'a';
  cout << win << endl;
  return 0;
}
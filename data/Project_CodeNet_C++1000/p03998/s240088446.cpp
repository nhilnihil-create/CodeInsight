#include <bits/stdc++.h>
using namespace std;
int main() {
  string sa, sb, sc;
  char ct = 'a';
  cin >> sa >> sb >> sc;
  reverse(sa.begin(), sa.end());
  reverse(sb.begin(), sb.end());
  reverse(sc.begin(), sc.end());
  while (1) {
    if (ct == 'a') {
      if (sa.empty()) {
        cout << 'A';
        return 0;
      }
      ct = sa[sa.size()-1];
      sa.pop_back();
    } else if (ct == 'b') {
      if (sb.empty()) {
        cout << 'B';
        return 0;
      }
      ct = sb[sb.size()-1];
      sb.pop_back();
    } else {
      if (sc.empty()) {
        cout << 'C';
        return 0;
      }
      ct = sc[sc.size()-1];
      sc.pop_back();
    }
  }
  return 0;
}
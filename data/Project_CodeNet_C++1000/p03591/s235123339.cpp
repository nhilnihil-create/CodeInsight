#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
  string s;
  cin >> s;
  bool ret = true;
  ret &= s.size() >= 4 && s[0] == 'Y';
  ret &= s.size() >= 4 && s[1] == 'A';
  ret &= s.size() >= 4 && s[2] == 'K';
  ret &= s.size() >= 4 && s[3] == 'I';
  if(ret) cout << "Yes\n";
  else cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}

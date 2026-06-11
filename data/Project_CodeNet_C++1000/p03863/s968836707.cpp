#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int n = s.size();
  vector <char> st;
  st.push_back(s[0]);
  st.push_back(s[1]);
  int cnt = 0;
  for (int i = 2; i < n; ++i) {
    char c = s[i];
    while (st.size() > 1 && st.rbegin()[1] != c) {
      ++cnt;
      st.pop_back();
    }
    st.push_back(c);
  }
  if (cnt % 2 == 0) {
    cout << "Second\n";
  } else {
    cout << "First\n";
  }
}


/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string X;
  cin >> X;
  const int64_t L = static_cast<int64_t>(X.length());
  stack<char> st;
  for (int64_t i = 0; i < L; ++i) {
    const char ch = X.c_str()[i];
    if (ch == 'S') {
      st.emplace(ch);
    } else {
      if (st.empty()) {
        st.emplace(ch);
      } else if (st.top() == 'S') {
        st.pop();
      } else {
        st.emplace(ch);
      }
    }
  }
  cout << st.size() << endl;
  return 0;
}

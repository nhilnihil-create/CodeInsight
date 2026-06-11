#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  stack<char> st;
  rep(i, n) {
    if (st.empty() || s[i] == 'S') {
      st.push(s[i]);
    } else if (s[i] == 'T' && st.top() == 'T') {
      st.push(s[i]);
    } else if (s[i] == 'T' && st.top() == 'S') {
      st.pop();
    }
  }

  cout << st.size() << endl;
  return 0;
}

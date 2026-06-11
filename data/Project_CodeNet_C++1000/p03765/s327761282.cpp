#include <bits/stdc++.h>
using namespace std;

int q;
string s, t;
vector<int> memos, memot;

int main() {
  cin >> s >> t;
  auto f = [](string &st) {
    int len = st.size();
    vector<int> res(len + 1, 0);
    for (int i = 0; i < len; ++i) res[i + 1] = res[i] + 1 + (st[i] == 'B');
    return res;
  };
  memos = f(s), memot = f(t);
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((memos[b] - memos[a - 1]) % 3 != (memot[d] - memot[c - 1]) % 3)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}

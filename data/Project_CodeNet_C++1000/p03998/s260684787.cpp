#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string S[3];
  for (auto &s : S) {
    cin >> s;
    reverse(begin(s), end(s));
  }

  int t{};
  auto s = &S[t];
  while (!s->empty()) {
    t = s->back() - 'a';
    s->pop_back();
    s = &S[t];
  }

  cout << char('A' + t) << endl;

  return 0;
}

#include <bits/stdc++.h>
#define sz(arr) (int)arr.size()
#define all(arr) arr.begin(), arr.end()

using namespace std;

void _cin() {}
template <class Head, class... Tail>
void _cin(Head&& head, Tail&&... tail) {
  cin >> head;
  _cin(forward<Tail>(tail)...);
}

#define Cin(T, ...) \
  T __VA_ARGS__;    \
  _cin(__VA_ARGS__)

int main() {
  Cin(string, s);
  string correct = "CODEFESTIVAL2016";

  int i = 0;
  int ans = 0;
  for (auto e : s) {
    if (s.at(i) != correct.at(i)) ans++;
    i++;
  }

  cout << ans << endl;

  return 0;
}
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
  Cin(int, h, w);
  vector<vector<string>> vv(h, vector<string>(w));
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) cin >> vv.at(i).at(j);

  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) {
      if (vv.at(i).at(j) == "snuke") {
        char col = 'A' + j;
        cout << col << (i + 1) << endl;
      }
    }

  return 0;
}
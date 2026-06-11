#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;

  vector<string> vs(h);
  for (int i = 0; i < h; ++i) {
    cin >> vs[i];
  }

  for (int i = 0; i < h; ++i) {
    cout << vs[i] << '\n';
    cout << vs[i] << '\n';
  }

  return 0;
}
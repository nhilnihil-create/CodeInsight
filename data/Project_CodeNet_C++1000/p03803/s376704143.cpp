#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;
  vector<int> va{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1};

  int pt_a, pt_b;
  for (int i = 0; i < va.size(); ++i) {
    if (a == va[i]) {
      pt_a = i;
    }

    if (b == va[i]) {
      pt_b = i;
    }
  }

  if (pt_a == pt_b) {
    cout << "Draw" << '\n';
  } else if (pt_a < pt_b) {
    cout << "Bob" << '\n';
  } else {
    cout << "Alice" << '\n';
  }

  return 0;
}
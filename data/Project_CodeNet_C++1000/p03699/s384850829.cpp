#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> ss(n);
  int sum = 0;
  for (int &s : ss) {
    cin >> s;
    sum += s;
  }

  if (sum % 10 == 0) {
    int minimum = 1000;
    for (const int &s : ss) {
      if (s % 10 != 0) {
        minimum = min(minimum, s);
      }
    }

    if (minimum == 1000) {
      cout << 0 << endl;
    } else {
      cout << sum - minimum << endl;
    }
  } else {
    cout << sum << endl;
  }

  return 0;
}
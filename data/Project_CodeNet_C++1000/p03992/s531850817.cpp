#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  for (int i = 0; i < 12; i++) {
    cout << s[i];
    if (i == 3) {
      cout << " ";
    }
  }
  cout << "\n";

}

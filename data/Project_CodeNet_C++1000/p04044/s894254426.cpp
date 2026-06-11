#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s.at(i);
  }
  
  sort(s.begin(), s.end());
  
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      cout << s.at(i) << endl;
      break;
    }
    cout << s.at(i);
  }
}

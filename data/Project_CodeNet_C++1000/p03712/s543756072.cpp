#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  cout << string(w + 2, '#') << endl;
  for (int i = 0; i < h; i++) {
    cout << '#' + a[i] + '#' << endl;
  }
  cout << string(w + 2, '#') << endl;
}

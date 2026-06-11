#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  vector<string> b(h*2);
  for (int i = 0; i < h*2; i++) {
    b[i] = a[i/2];
  }
  for (int i = 0; i < h*2; i++) {
    cout << b[i] << endl;
  }
}
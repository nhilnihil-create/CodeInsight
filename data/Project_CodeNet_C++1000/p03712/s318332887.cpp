#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> vec(h);
  for (int i = 0; i < h; i++) {
    cin >> vec.at(i);
  }
  for (int i = 0; i < h + 2; i++) {
    if (i == 0 || i == h + 1) {
      for (int j = 0; j < w + 2; j++) {
        cout << "#";
      }
      cout << endl;
    }
    else {
      cout << '#' << vec.at(i-1) << '#' << endl;
    }
  }
}
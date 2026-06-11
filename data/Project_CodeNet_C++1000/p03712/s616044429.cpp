#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  string ss = "";
  for (int i = 0; i < w+2; i++) {
     ss += "#";
  }

  cout << ss << endl;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    cout << "#" << s << "#" << endl;
  }
  cout << ss << endl;
}

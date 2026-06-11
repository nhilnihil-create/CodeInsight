#include <bits/stdc++.h>
using namespace std;
int main(){
  int x, y;
  cin >> x >> y;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      string a;
      cin >> a;
      if (a == "snuke") {
        cout << (char)(j + 'A') << 1 + i;
        return 0;
      }
    }
  }
}
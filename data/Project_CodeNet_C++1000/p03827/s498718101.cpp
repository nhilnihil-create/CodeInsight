#include <iostream>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int x = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'I') {
      x++;
      if (mx < x) {
        mx = x;
      }
    } else if (s[i] == 'D') {
      x--;
    }
  }
  cout<<mx<<endl;
  return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
  int h, w;
  string s;
  cin >> h >> w;
  string y(w + 2, '#');
  cout << y << endl;
  for (int i = 0; i < h; i++) {
    cin >> s;
    cout << '#' << s << '#' << endl;
  }
  cout << y << endl;

  return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;
  int n = static_cast<int>(str.size());
  for (int i = 1; i < n; ++i) {
    int a = (n - i) / 2;
    int b = n - i - a;
    if (a != b)
      continue;
    string sa = str.substr(0, a);
    string sb = str.substr(a, b);
    if (sa != sb)
      continue;
    cout << n - i << endl;
    break;
  }
}

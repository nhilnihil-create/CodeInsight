#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;
  int n = static_cast<int>(str.size());
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == 'S') {
      ++cnt1;
    }
    if (str[i] == 'T' && 0 < cnt1) {
      --cnt1;
      ++cnt2;
    }
  }
  cout << n - cnt2 * 2 << endl;
}

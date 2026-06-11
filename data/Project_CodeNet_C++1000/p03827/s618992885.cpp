#include <iostream>
using namespace std;
int main() {
  string S;
  cin >> S >> S;
  int x{}, m{};
  for (auto c : S) {
    x += c - 'D' ? 1 : -1;
    m = m < x ? x : m;
  }
  cout << m << endl;
  return 0;
}

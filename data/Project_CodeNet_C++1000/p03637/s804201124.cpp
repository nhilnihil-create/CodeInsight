#include <iostream>

using namespace std;

int main() {
  int N, a, p{}, q{};
  cin >> N;
  while(cin >> a) {
    if (a % 4 == 0) ++p;
    else if (a % 2) ++q;
  }
  cout << (q <= p + !(N-p-q) ? "Yes" : "No") << endl;
}

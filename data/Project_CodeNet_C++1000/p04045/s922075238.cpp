#include <iostream>

using namespace std;

int main() {
  int N, d, D[10]{};
  cin >> N >> d;
  while (cin >> d) D[d] = 1;
  for(int i = N;; ++i) {
    int j{i}, hate{};
    while(j) hate |= D[j%10], j /= 10;
    if (!hate) {
      cout << i << endl;
      break;
    } 
  }
}

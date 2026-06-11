#include <iostream>

using namespace std;

int main() {
  int N, A;
  cin >> N;
  while (cin >> A) if (A%2) N = !N;
  cout << (N ? "YES" : "NO") << endl;
}

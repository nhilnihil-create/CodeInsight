#include <iostream>

using namespace std;

int main() {
  string S;
  cin >> S;

  char current = S[0];
  int cnt = 0;
  for (const char &c : S) {
    if (current != c) {
      cnt++;
      current = c;
    }
  }

  cout << cnt << endl;
}

#include <iostream>

using namespace std;

int main() {
  int X, A, B;
  cin >> X >> A >> B;
  const char* result = "dangerous";
  if (B <= A) {
    result = "delicious";
  } else if (B - A <= X) {
    result = "safe";
  }
  cout << result << endl;
  return 0;
}

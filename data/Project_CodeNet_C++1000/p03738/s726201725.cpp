#include <iostream>

using namespace std;

int main() {
  string A,B;
  cin >> A >> B;

  int comp{};
  if (A.size() > B.size()) {
    comp = 1;
  } else if (A.size() < B.size()) {
    comp = -1;
  } else if (A < B) {
    comp = -1;
  } else if (B < A) {
    comp = 1;
  }

  cout << (comp == 1 ? "GREATER" : comp == -1 ? "LESS" : "EQUAL" ) << endl;
  return 0;
}

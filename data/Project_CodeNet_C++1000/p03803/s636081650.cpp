#include <iostream>

using namespace std;
int main() {
  int A, B;
  cin >> A >> B;

  int card[] = {13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  if (card[A-1] == card[B-1]) {
    cout << "Draw" << endl;
  }
  else if (card[A-1] > card[B-1]) {
    cout << "Alice" << endl;
  }
  else {
    cout << "Bob" << endl;
  }
}

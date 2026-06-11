#include <iostream>
#include <string>
using namespace std;

int main() {
  string X; cin >> X;
  int stack = 0, puyo = 0;
  for (int i = 0; i < (int)X.size(); ++i) {
    if (X[i] == 'S') ++stack;
    else if (stack > 0) --stack, ++puyo;
  }
  cout << (int)X.size() - puyo*2 << endl;
}

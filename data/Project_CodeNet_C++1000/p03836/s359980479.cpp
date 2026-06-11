#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  // first go horizon
  for (int i = 0; i < tx - sx; ++i)
    cout << "R";

  // first go verticall
  for (int i = 0; i < ty - sy; ++i)
    cout << "U";

  // first back horizon
  for (int i = 0; i < tx - sx; ++i)
    cout << "L";

  // first back vertical
  for (int i = 0; i < ty - sy; ++i)
    cout << "D";

  // second go horizon
  cout << "D";
  for (int i = 0; i < tx - sx + 1; ++i)
    cout << "R";

  // second go vertical
  for (int i = 0; i < ty - sy + 1; ++i)
    cout << "U";
  cout << "L";

  // second back horizon
  cout << "U";
  for (int i = 0; i < tx - sx + 1; ++i)
    cout << "L";

  // second back vertical
  for (int i = 0; i < ty - sy + 1; ++i)
    cout << "D";
  cout << "R";

  cout << endl;

  return 0;
}
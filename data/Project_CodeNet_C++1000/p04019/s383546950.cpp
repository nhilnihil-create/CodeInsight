#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  string s;
  cin >> s;

  int south = 0;
  int north = 0;
  int east = 0;
  int west = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'S')
      ++south;
    else if (s[i] == 'N')
      ++north;
    else if (s[i] == 'E')
      ++east;
    else if (s[i] == 'W')
      ++west;
  }

  // check north and south
  if (!((south == 0 && north == 0) || (south > 0 && north > 0))) {
    cout << "No" << endl;
    return 0;
  }

  // check east and west
  if (!((east == 0 && west == 0) || (east > 0 && west > 0))) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;

  return 0;
}
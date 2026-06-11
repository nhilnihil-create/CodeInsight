#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  string S;
  cin >> S;
  int N = S.size();
  bool east, west, north, south;
  east = west = north = south = false;
  rep(i, N) {
    if (S[i] == 'E')
      east = true;
    else if (S[i] == 'W')
      west = true;
    else if (S[i] == 'N')
      north = true;
    else if (S[i] == 'S')
      south = true;
  }

  if (east != west || north != south)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}

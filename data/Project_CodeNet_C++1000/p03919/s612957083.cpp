#include <iostream>

using namespace std;

int
main()
{
  int H, W;
  string s;
  const string snuke = "snuke";
  cin >> H >> W;
  for (int j = 0; j < H; ++j) {
    for (int i = 0; i < W; ++i) {
      cin >> s;
      if (s == snuke) {
	cout << char('A' + i) << j + 1 << "\n";
	return 0;
      }
    }
  }
  return 0;
}

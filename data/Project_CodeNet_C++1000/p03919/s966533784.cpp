#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  int H, W;
  cin >> H >> W;
  
  string key = "snuke";
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      string temp;
      cin >> temp;
      char tmp = 'A' + j;
      if (temp == key) cout << tmp << i + 1 << endl;;
    }
  }

  return 0;
}

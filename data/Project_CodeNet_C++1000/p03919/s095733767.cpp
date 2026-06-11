#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<string>> S(H, vector<string>(W));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> S[i][j];

  char ans1 = 'A';
  int ans2 = 1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == "snuke") {
        ans1 += j;
        ans2 += i;
      }
    }
  }

  cout << ans1 << ans2 << endl;
}
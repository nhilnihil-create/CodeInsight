#include<bits/stdc++.h>
using namespace std;

int main () {
  int H, W;
  cin >> H >> W;
  char moji;
  vector<char> ABC(0);
  for (moji = 'A'; moji <= 'Z'; moji++) {
    ABC.push_back(moji);
  }

  vector<vector<string>> data(H,vector<string>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) == "snuke") {
        cout << ABC.at(j) << i + 1 << endl;
        return 0;
      }
    }
  }
}
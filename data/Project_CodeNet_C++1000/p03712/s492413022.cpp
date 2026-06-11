#include <bits/stdc++.h>
using namespace std;

int main() {
  int H;
  int W;

  cin >> H >> W;

  vector<string> vec(H);

  for (int i = 0; i < H; i++){
    cin >> vec.at(i);
  }
  for(int i = 0; i < W + 1; i++){
    cout << "#";
  }
    cout << "#" << endl;
  for(int i = 0; i < H; i++){
      cout << "#" + vec.at(i) + "#" << endl;
  }
  for(int i = 0; i < W + 1; i++){
    cout << "#";
  }
  cout << "#" << endl;
}

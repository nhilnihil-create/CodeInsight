#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  for(int i = 0; i < W + 2; i++){
    cout << "#";
  }
  cout << endl;
  for(int i = 0; i < H; i++){
    cout << "#";
    string A;
    cin >> A;
    for(int o = 0; o < W; o++){
      cout << A.at(o);
    }
    cout << "#" << endl;
  }
  for(int i = 0; i < W + 2; i++){
    cout << "#";
  }
  cout << endl;
}

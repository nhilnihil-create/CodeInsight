#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> photo;
  string frame;
  for(int i = 0; i < W + 2; i++){
    frame += '#';
  }
  photo.push_back(frame);
  for(int i = 0; i < H; i++){
    string raw, tempraw;
    raw += '#';
    cin >> tempraw;
    raw += tempraw;
    raw += '#';
    photo.push_back(raw);
  }
  photo.push_back(frame);
  for(int i = 0; i < photo.size(); i++){
    cout << photo.at(i) << endl;
  }
}
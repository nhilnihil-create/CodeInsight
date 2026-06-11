#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  char p[h][w];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> p[i][j];
    }
  }
  for(int i = 0; i < w+2; i++){
    cout << "#";
  }
  cout << endl;
  for(int i = 0; i < h; i++){
    cout << "#";
    for(int j = 0; j < w; j++){
      cout << p[i][j];
    }
    cout << "#" << endl;
  }
  for(int i = 0; i < w+2; i++){
    cout << "#";
  }
  cout << endl;
}
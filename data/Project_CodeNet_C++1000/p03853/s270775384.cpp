#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector <vector<char>> vec1(H, vector<char>(W));
  
  for (int i = 0 ; i < H ; i++ ){
    for (int j = 0 ; j < W ; j++ ){
      cin >> vec1.at(i).at(j);
    }
  }
  
  vector <vector<char>> vec2(H * 2, vector<char>(W));
  for ( int i = 0 ; i < H * 2 ; i++ ){
    for ( int j = 0 ; j < W ; j++ ){
        vec2.at(i).at(j) = vec1.at(i/2).at(j);
      cout << vec2.at(i).at(j) ;
      }
    cout << endl;
  }
}
  
  
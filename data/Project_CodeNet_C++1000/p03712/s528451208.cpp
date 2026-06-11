#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector <vector <char>> vec(H, vector<char>(W));
  for ( int i = 0 ; i < H ; i++ ){
    for ( int j = 0 ; j < W ; j++ ){
      cin >> vec.at(i).at(j);
    }
  }
  
  vector <vector <char>> vecN( H + 2, vector<char>(W + 2, '%'));
  for ( int i = 0 ; i < H ; i++ ){
    for ( int j = 0 ; j < W ; j++ ){
      vecN.at(i + 1).at(j + 1) = vec.at(i).at(j);
    }
  }
  
  for ( int i = 0 ; i < H + 2 ; i++ ){
    for ( int j = 0 ; j < W + 2 ; j++ ){
      if (vecN.at(i).at(j) == '%'){
        vecN.at(i).at(j) = '#';
      }
    }
  }

  for ( int i = 0 ; i < H + 2 ; i++ ){
    for ( int j = 0 ; j < W + 2 ; j++ ){
      cout << vecN.at(i).at(j);
    }
    cout << endl;
  }
}

  
  
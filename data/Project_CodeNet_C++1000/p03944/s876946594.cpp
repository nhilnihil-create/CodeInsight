#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, H;
  cin >> W >> H;
  vector <vector<int>> menseki(H, vector<int>(W));
  
  int N;
  cin >> N;
  
  vector <vector<int>> Y(N, vector<int>(3));
  for ( int i = 0; i < N ; i++ ){
    for ( int j = 0 ; j < 3 ; j++ ){
      cin >> Y.at(i).at(j);
    }
  }
  

  for ( int i = 0 ; i < N ; i++ ){
    if ( Y.at(i).at(2) == 1 ){
      for ( int j = 0 ; j < H ; j ++ ){
        for ( char k = 0 ; k < Y.at(i).at(0) ; k++ ){
          menseki.at(j).at(k) = 1;
        }
      }
    }
    if ( Y.at(i).at(2) == 2 ){
      for ( int j = 0 ; j < H ; j ++ ){
        for ( char k = Y.at(i).at(0) ; k < W ; k++ ){
          menseki.at(j).at(k) = 1;
        }
      }
    }
    if ( Y.at(i).at(2) == 3 ){
      for ( int j = 0 ; j < Y.at(i).at(1) ; j ++ ){
        for ( char k = 0 ; k < W ; k++ ){
          menseki.at(j).at(k) = 1;
        }
      }
    }
    if ( Y.at(i).at(2) == 4 ){
      for ( int j = Y.at(i).at(1) ; j < H ; j ++ ){
        for ( char k = 0 ; k < W ; k++ ){
          menseki.at(j).at(k) = 1;
        }
      }
    } 
  }
  int answer;
  for ( int i = 0; i < H ; i++ ){
    for ( int j = 0 ; j < W ; j++ ){
      if ( menseki.at(i).at(j) == 0 ){
      answer++ ;
      }
    }
  }
  cout << answer ;
}
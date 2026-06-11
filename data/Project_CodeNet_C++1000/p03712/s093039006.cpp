#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  char A;
  
  for( int i = 0; i < H + 2; ++i ){
    for( int j = 0; j < W + 2; ++j ){
      if( i == 0 ){
        cout << '#';
      }else if( i == H + 1 ){
        cout << '#';
      }else if( j == 0 ){
        cout << '#';
      }else if( j == W + 1 ){
        cout << '#';
      }else{
        cin >> A;
        cout << A;
      }
    }
    cout << endl;
  }
}
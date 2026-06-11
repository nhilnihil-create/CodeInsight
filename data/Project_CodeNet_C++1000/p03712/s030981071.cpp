#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  for( int i=0; i<H+2; i++ ){
    cout << "#";
    for( int j=0; j<W; j++ ){
      if( (i == 0) || (i == (H + 1)) ){
        cout << "#";
      }
      else{
        char a;
        cin >> a;
        cout << a;
      }
    }
    cout << "#" << endl;
  }
}
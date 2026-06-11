#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  char a[H][W];
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> a[i][j];
    }
  }

  for(int i=0; i<W+2; i++){
    cout << '#';
  }
  cout << endl;
  
  for(int i=0; i<H; i++){
    cout << '#';
    for(int j=0; j<W; j++){
      cout << a[i][j];
    }
    cout << '#' << endl;
  }
  
  for(int i=0; i<W+2; i++){
    cout << '#';
  }
  cout << endl;
  
  return 0;
}

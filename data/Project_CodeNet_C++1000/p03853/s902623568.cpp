#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  char c[H][W];
  for(int i=0; i<H; ++i){
    for(int j=0; j<W; ++j){
      cin >> c[i][j];
    }
  }

  char resC[2*H][W];
  for(int i=0; i<H; ++i){
    for(int j=0; j<W; ++j){
      resC[2*i][j]=c[i][j];
      resC[2*i+1][j]=c[i][j];
    }
  }
  
  for(int i=0; i<2*H; ++i){
    for(int j=0; j<W; ++j){
      cout << resC[i][j];
    }
    cout << endl;
  }
}


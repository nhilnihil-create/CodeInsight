#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int h, w;
  cin >> h >> w;
  vector<vector<char>> pix(h, vector<char>(w));
  vector<vector<char>> lpix(2*h, vector<char>(w,'.'));
  
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> pix.at(i).at(j);
    }
  }
  
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      lpix.at(2*i).at(j) = pix.at(i).at(j);
      lpix.at(2*i+1).at(j) = pix.at(i).at(j);
    }
  }
  
  for(int i=0; i<2*h; i++){
    for(int j=0; j<w; j++){
      cout << lpix.at(i).at(j);
    }
    cout << endl;
  }
  
}
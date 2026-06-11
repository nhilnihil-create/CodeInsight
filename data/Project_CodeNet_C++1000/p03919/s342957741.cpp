#include <iostream>
#include <string>
using namespace std;

int main(){
  int h, w;
  string s;
  int ansi, ansj;
  
  cin >> h >> w;
  for ( int i = 0; i < h; i++ ){
    for ( int j = 0; j < w; j++){
      cin >> s;
      if ( s == "snuke" ){
        ansi = i;
        ansj = j;
      }
    }
  }
  char c = 'A' + ansj;
  cout << c << ansi + 1 << endl;
}
#include <iostream>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;
  
  char a[h+2][w+2];
  for(int i = 1; i < h+1; ++i){
    for(int j = 1; j < w+1; ++j){
      cin >> a[i][j];
    }
  }
  
  for(int i = 0; i < h+2; ++i){
    for(int j = 0; j < w+2; ++j){
      if(i == 0 || j == 0 || i == h+1 || j == w+1) cout << '#';
      else cout << a[i][j];
    }
    cout << endl;
  }
}
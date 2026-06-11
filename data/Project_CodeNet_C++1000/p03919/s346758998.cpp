#include<iostream>
#include<algorithm>
using namespace std;

#define COLUMN 100
#define ROW 100

int main(){
  int h,w;
  cin >> h >> w;
  string s[ROW][COLUMN];
  for (int i = 0; i<h; i++){
    for (int j = 0; j<w; j++){
      cin >> s[i][j];
      if (s[i][j] == "snuke"){
        char r = 'A'+j;
        cout << r << i+1 << endl;
        break;
      }
    }
  }
  return 0;
}
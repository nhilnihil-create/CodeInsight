#include <iostream>
#include <string>
using namespace std;

int main(){
  int h, w; cin >> h >> w;

  string grid[h][w];
  char l; int c;
  for(int y=0; y<h; y++){
    for(int x=0; x<w; x++){
      cin >> grid[y][x];
      if(grid[y][x] == "snuke"){
        l = x + 'A'; 
        c = y + 1;
      }
    }
  }

  cout << l << c << endl;

  return 0;
}

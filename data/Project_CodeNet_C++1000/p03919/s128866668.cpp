#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
  int h, w;
  cin >> h >> w;

  string s;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> s;
      if(s == "snuke"){
        printf("%c%d\n", 'A' + j, i + 1);
      }
    }
  }

  return 0;
}

#include <iostream>

using namespace std;

int main(){
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;

  for (int i = sx; i < tx; i++){
    printf("R");
  }
  for (int i = sy; i < ty; i++){
    printf("U");
  }
  for (int i = sx; i < tx; i++){
    printf("L");
  }
  for (int i = sy; i < ty; i++){
    printf("D");
  }

  printf("D");
  for (int i = sx; i < tx + 1; i++){
    printf("R");
  }
  for (int i = sy; i < ty + 1; i++){
    printf("U");
  }
  printf("L");
  printf("U");
  for (int i = sx; i < tx + 1; i++){
    printf("L");
  }
  for (int i = sy; i < ty + 1; i++){
    printf("D");
  }
  printf("R\n");
}

#include <iostream>

using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  char a[H][W];

  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < W + 2; i++){
    printf("#");
  }
  printf("\n");

  for (int i = 0; i < H; i++){
    printf("#");
    for (int j = 0; j < W; j++){
      printf("%c",a[i][j]);
    }
    printf("#\n");
  }
  
  for (int i = 0; i < W + 2; i++){
    printf("#");
  }
  printf("\n");
}

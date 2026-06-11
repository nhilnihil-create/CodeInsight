#include <cstdio>

char s[2][2] = { 'R', 'Y', 'G', 'B' };

int main(){
  int H, W, D; scanf("%d%d%d", &H, &W, &D);

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      int x = i + W - j, y = i + j;
      putchar(s[x / D & 1][y / D & 1]);
    }
    printf("\n");
  }
  return 0;
}
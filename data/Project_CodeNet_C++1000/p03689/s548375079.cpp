#include <bits/stdc++.h>
 
using namespace std;
 
const int X = 3999;
 
int a[1234][1234];
 
int main() {
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  if(H%h==0&&W%w==0)return puts("No"),0;
  puts("Yes");
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i % h == h - 1 && j % w == w - 1) {
        a[i][j] = -X * (h * w - 1) - 1;
      } else {
        a[i][j] = X;
      }
    }
  }
  // long long total = 0;
  // for (int i = 0; i < H; i++) {
  //   for (int j = 0; j < W; j++) {
  //     total += a[i][j];
  //   }
  // }
  // if (total <= 0) {
  //   puts("No");
  //   return 0;
  // }
  // puts("Yes");
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (j > 0) putchar(' ');
      printf("%d", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
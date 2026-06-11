#include<iostream>
int main(void){
  int H,W;
  std::cin >> H >> W;
  char space[H+2][W+2];
  for (int i=1;i<H+1;i++){
    for (int j=1;j<W+1;j++){
      std::cin >> space[i][j];
    }
  }
  for(int i=0;i<H+2;i++){
    for (int j=0; j<W+2;j++){
      if (i==0 || i == H+1 || j == 0 || j == W+1){
        space[i][j] = '#';
      }
    }
  }
  std::cout << std::endl;
  for (int i=0;i<H+2;i++){
    for (int j= 0;j<W+2;j++){
      std::cout << space[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}
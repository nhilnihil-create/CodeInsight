#include <bits/stdc++.h>
using namespace std;
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;
int H,W,d;

int main(int argc, char *argv[])
{
  scanf("%d%d%d",&H,&W,&d);
  int stride = (W/d+1)*d;
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int x,y;
      x = stride+i+j;y = stride+i-j;
      if((x+1)/d%2==1&&(y+1)/d%2==1) printf("R");
      else if((x+1)/d%2==0&&(y+1)/d%2==1) printf("G");
      else if((x+1)/d%2==0&&(y+1)/d%2==0) printf("B");
      else if((x+1)/d%2==1&&(y+1)/d%2==0) printf("Y");
    }
    printf("\n");
  }
  
  return 0;
}

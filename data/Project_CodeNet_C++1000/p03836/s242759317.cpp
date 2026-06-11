#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
  int sx,sy,tx,ty;
  int rx,ry;

  scanf("%d %d %d %d", &sx, &sy, &tx, &ty);

  rx = tx - sx;
  ry = ty - sy;

  int i;

  for(i = 0;i < ry;i++) printf("U");
  for(i = 0;i < rx;i++) printf("R");
  for(i = 0;i < ry;i++) printf("D");
  for(i = 0;i < rx;i++) printf("L");
  printf("L");
  for(i = 0;i <= ry;i++) printf("U");
  for(i = 0;i <= rx;i++) printf("R");
  printf("DR");
  for(i = 0;i <= ry;i++) printf("D");
  for(i = 0;i <= rx;i++) printf("L");
  printf("U\n");


  return 0;
}
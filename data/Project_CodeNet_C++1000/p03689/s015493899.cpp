#include<bits/stdc++.h>
using namespace std;
#define FOR(i,x,y) for(int i=(int)x; i<(int)y; ++i)
int main(){
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  if(H%h==0 && W%w==0){
    printf("No\n");
  }else{
    printf("Yes\n");
    FOR(i,0,H){
      FOR(j,0,W){
        if(i%h==h-1 && j%w==w-1) printf("-999999 ");
        else if(i%h==0 && j%w==0) printf("999998 ");
        else printf("0 ");
      }
      printf("\n");
    }
  }
  return 0;
}

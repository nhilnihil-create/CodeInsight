#include<bits/stdc++.h>
using namespace std;

char ans[600][600];

void solve_odd(int h,int w,int d){
  for(int i = 0;i < h;++i){
    for(int j = 0;j < w;++j){
      if((i+j) % 2 == 0)
        ans[i][j] = 'R';
      else
        ans[i][j] = 'B';
    }
  }
}

void solve_even(int h,int w,int d){
  for(int i = 0;i < h;++i){
    for(int j = 0;j < w;++j){
      int a = ((i+j)/d)%2;
      int b = ((j-i+1000*d)/d)%2;
      if(a == 0 && b == 0){
        ans[i][j] = 'R';
      }else if(a == 0 && b == 1){
        ans[i][j] = 'G';
      }else if(a == 1 && b == 0){
        ans[i][j] = 'B';
      }else if(a == 1 && b == 1){
        ans[i][j] = 'Y';
      }
    }
  }
}

int main(void){
  int h,w,d;
  cin >> h >> w >> d;
  if(d % 2 == 1)solve_odd(h,w,d);
  else solve_even(h,w,d);
  for(int i = 0;i < h;++i){
    for(int j = 0;j < w;++j){
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}

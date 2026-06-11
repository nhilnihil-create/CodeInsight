#include <bits/stdc++.h>
using namespace std;

int H,W;
void nextpos(int &x, int &y){
  if(x%2==0){
    if(y==W-1) x++;
    else y++;
  }else{
    if(y==0) x++;
    else y--;
  }
  return;
}

int main() {
  cin >> H >> W;
  int coloring[110][110];
  
  int N; cin >> N;
  int cx=0;
  int cy=0;
  for(int i=0; i<N; i++){
    int ai; cin >> ai;
    while(ai>0){
      coloring[cx][cy]=i+1;
      nextpos(cx,cy);
      ai--;
    }
  }
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cout << coloring[i][j];
      if(j==W-1) cout << endl;
      else cout << " ";
    }
  }
}
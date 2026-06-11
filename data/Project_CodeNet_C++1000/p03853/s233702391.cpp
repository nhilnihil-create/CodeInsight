#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int H, W;
  cin >> H >> W;
  char C[H][W];
  rep(i, H)
    rep(j, W)
    cin >> C[i][j];
  //入力終了

  rep(i, H){
    //各i行目に対して，W列分の表示を2回行う
    rep(j, 2){
      rep(k, W)
	cout << C[i][k] ;
      cout << endl;
    }
  }
  

  return 0;
}

#include<iostream>
using namespace std;

int main(){
  string sk[30][30];
  int H,W;
  cin >> H >> W ;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> sk[i][j];
      if(sk[i][j] == "snuke")
        printf("%c%d",j+'A',i+1);
    }
  }
  return 0;
}


#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  int W,H,N;
  cin >> W >> H >> N;
  int xn[N],yn[N],an[N];
  for(int i=0; i < N; ++i)cin >> xn[i] >> yn[i] >> an[i];

  int resW[2]={0,W},resH[2]={0,H};
  for(int i = 0; i < N; ++i){
    if(an[i] == 1){
      if(resW[0] < xn[i]){
        resW[0] = xn[i];
      }
    }
    if(an[i] == 2){
      if(resW[1] > xn[i]){
        resW[1] = xn[i];
      }
    }
    if(an[i] == 3){
      if(resH[0] < yn[i]){
        resH[0] = yn[i];
      }
    }
    if(an[i] == 4){
      if(resH[1] > yn[i]){
        resH[1] = yn[i];
      }
    }
  }
  if(resW[0] > resW[1] || resH[0] > resH[1]){
    cout << '0' << endl;
  }else{
    cout << (resW[1] - resW[0]) * (resH[1] - resH[0]) << endl;
  }
}


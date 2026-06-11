#include <bits/stdc++.h>
using namespace std;

/*
レート 1-399：灰色
レート 400-799：茶色
レート 800-1199：緑色
レート 1200-1599：水色
レート 1600-1999：青色
レート 2000-2399：黄色
レート 2400-2799：橙色
レート 2800-3199：赤色
*/
int main() {
  int N;
  cin >> N;
  vector<int>iro(8);
  int kami = 0;
  vector<int>vec(N,0);
  for(int i=0; i<N; i++){
    cin >> vec[i];
    if(vec[i] >= 3200){
      kami++;
    }
    else{
      iro[vec[i]/400]++;
    }
  }
  int syou = 0;
  for(int i=0; i<8; i++){
    if(iro[i] != 0){
      syou++;
    }
  }
  cout << max(syou,1) << " " << syou+kami << endl;
}

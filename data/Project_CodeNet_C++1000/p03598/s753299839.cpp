#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;

  //移動距離
  int intTotalMove = 0;

  int X;

  for(int i = 1; i <= N; i++){

    cin >> X;
    
    //Aの方が近い場合
    if(X < K - X){
      intTotalMove = intTotalMove + (X * 2);
    }
    else{
      intTotalMove = intTotalMove + ((K - X) * 2);
    }
  }    
    
  cout << intTotalMove << endl;
}

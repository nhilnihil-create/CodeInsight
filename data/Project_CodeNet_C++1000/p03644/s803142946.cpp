#include <iostream>

using namespace std;

int main(void){
  int N;
  cin >> N;
  //入力終了

  //答えは，必ず2の冪乗になることに注目する
  int n;
  for(n=N; n>0; n--){
    int tmp = n;
    //偶数である間割り続ける
    while(tmp%2 == 0 && tmp>=0)
      tmp /= 2;
    
    //2^0までたどり着けば終了
    if(tmp == 1)
      break;
  }

  //解答
  cout << n << endl;

  return 0;
}

#include <iostream>
using namespace std;

int main(){
  long long N, M;
  cin >> N >> M;
  //ここまで入力

  long long count = 0;
  //c型が不足しているとき
  if(M < 2*N){
    //c型の数に合わせて"scc"を作れる
    cout << M/2 << endl;
    return 0;
  }
  //s型の方が不足しているとき
  else{
    //s型の分を使い切る
    count += N;
    //s型で使った分c型も使う
    M = M - 2*N;
    //c型のみで"scc"を作るには4つ必要
    count += M/4;
  }

  //解答
  cout << count << endl;

  return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define rep(i, n) for(int i=0; i<=n; i++)

using namespace std;

int main(){
  int N, M, K;
  cin >> N >> M >> K;
  // 入力終了

  // ボタンを押す順はなんでもいい
  // i回行ボタンを押した後，j回列ボタンを押す全探索をする
  // 最初に行ボタンによりMi個のマスが黒くなる
  // 次に，列ボタンでNj個のマスを黒くすると考えると，
  // 交差部分のij個のマスを2回黒とカウントしてしまうので引く
  
  rep(i, N){
    rep(j, M){
      if(M*i + N*j - 2*i*j == K){
	cout << "Yes" << endl;
	return 0;
      }
    }
  }

  // 上のループを抜けたら無理
  cout << "No" << endl;
  
  return 0;
}

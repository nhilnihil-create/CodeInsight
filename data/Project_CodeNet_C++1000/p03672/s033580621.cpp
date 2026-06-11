#include <iostream>

using namespace std;

int main(void){
  string S;
  cin >> S;
  //入力終了

  int N = S.size();
  
  //最初に，末尾の文字を消去しておく
  S.erase(N-1);
  
  for(int i=0; i<N; i++){
    //1文字ずつ末尾から消していく
    S.erase(N-1-i);
    //文字列の長さが奇数なら偶文字列でない
    if(S.size()%2 == 1)
      continue;

    //
    bool flag = true;

    int n = S.size();
    //偶文字列かの判定
    for(int i=0; i<n/2; i++){
      if(S[i] != S[i+n/2])
	flag = false;
    }
    
    //解答
    if(flag){
      cout << n << endl;
      return 0;
    }
  }
  
  return 0;
}

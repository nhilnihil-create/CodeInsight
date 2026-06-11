#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int N;
  string S;
  cin >> N >> S;
  //入力終了

  int x = 0, max = 0;
  rep(i, N){
    //条件に従って+か-かする
    if(S[i] == 'I')
      x++;
    else
      x--;
    //最大値の更新
    if(x > max)
      max = x;
  }

  //解答
  cout << max << endl;
  
  return 0;
}

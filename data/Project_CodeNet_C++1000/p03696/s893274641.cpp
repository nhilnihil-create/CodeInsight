#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int N;
  cin >> N;
  string S;
  cin >> S;
  //入力終わり

  int size = S.size();

  //カッコの対応を数える配列
  // )より(がいくつ多いか
  int count[size+1];
  count[0] = 0;
  rep(i, size){
    count[i+1] = count[i];
    // ( があれば+1
    if(S[i] == '(')
      count[i+1]++;
    // )があれば-1
    else
      count[i+1]--;
  }

  //左側に挿入する( の数
  int l_ins = size;
  //count[] の最小値になる
  rep(i, size+1)
    if(count[i] < l_ins)
      l_ins = count[i];

  //count[]の仕様上，符号反転
  l_ins *= -1;

  //右側に挿入する)の数
  int r_ins;
  r_ins = count[size] + l_ins;

  //左側に挿入する文字列生成
  string l;
  rep(i, l_ins)
    l = l + '(';

  //右側に挿入する文字列生成
  string r;
  rep(i, r_ins)
    r = r + ')';

  //解答
  cout << l + S + r << endl;
  
  return 0;
}

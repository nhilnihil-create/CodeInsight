#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  string S;
  cin >> S;
  //入力終了

  //文字が既に出現したか
  int appeared[26];
  rep(i, 26)
    appeared[i] = 0;

  //Sの各文字の出現情報をappered[]に記録
  rep(i, S.size() )
    appeared[S[i]-'a' ]++;

  //Sに現れない文字(辞書順最小)が見つかればそこで終了
  rep(i, 26){
    if(appeared[i] == 0){
      cout << (char)(i+'a') << endl;
      return 0;
    }
  }

  //上のループを抜ける＝Sに現れない文字がない
  cout << "None" << endl;
  
  return 0;
}

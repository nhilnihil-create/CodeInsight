#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
string S;	
  cin >> S;
//入力終了
  
  int N = S.size();
  
  //出現したかどうか(falseで初期化)
  bool appeared[26];
  rep(i, 26)
    appeared[i] = false;
  
  for(int i=0; i<S.size(); i++){
    int num = S[i]-'a';
    //既に出現していればnoで終了
	if(appeared[num] == true){
		cout << "no" << endl;
  		return 0;
  	}
    //出現済みにする
    appeared[num] = true;
  }
  
  cout << "yes" << endl;

return 0;
}

#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  string O, E;
  cin >> O >> E;
  // 入力終了

  // OとEを交互に出力
  rep(i, O.size()-1 ){
    cout << O[i] << E[i] ;
  }

  // Oの末尾
  cout << O[ O.size()-1 ];
  
  // 文字列長が同じならEの末尾も出力
  if(O.size() == E.size() )
    cout << E[ E.size()-1 ];
  
  cout << endl;  

  return 0;
}

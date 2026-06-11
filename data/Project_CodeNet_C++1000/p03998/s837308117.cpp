
//要素の削除　https://riptutorial.com/ja/cplusplus/example/2156/%E8%A6%81%E7%B4%A0%E3%81%AE%E5%89%8A%E9%99%A4
/*回答の作り方　
(1)ある終了条件のifとreturn 0;
(2)別終了条件　else if,return 0;
(3)全体をwhile(1)でつなぐ,循環を構築するの3段階。
この循環手法はいろいろ応用が効く*/

#include <bits/stdc++.h>
using namespace std;
 
int main(){
 //各種カードを入力する。
  string A,B,C;
  cin>>A>>B>>C;

//カードの最初の指定方法
  char c=A[0];
  A.erase(0,1);
  while(1){
    if(c=='a'){
//カードがなくなったら
      if(A.size()==0){
        cout<<'A'<<endl;
//return 0で終了させる。
        return 0;
      }
//Aのカードを切る。while文なので循環をする。先頭のカードは、a,b,cのどれか。
      c=A[0]; A.erase(0,1);
    }else if(c=='b'){
//終了条件の書き方がポイント
      if(B.size()==0){
        cout<<'B'<<endl;
        return 0;
      }
//Bのカードを切る。
      c=B[0]; B.erase(0,1);
    }else{
      if(C.size()==0){
        cout<<'C'<<endl;
        return 0;
      }
      c=C[0]; C.erase(0,1); 
    }
  }
}

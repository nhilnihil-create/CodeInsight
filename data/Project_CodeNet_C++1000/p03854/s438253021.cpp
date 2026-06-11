#include <bits/stdc++.h>

using namespace std;
int main(){
  string S;     //入力
  cin >> S;
  string a,b,c;     //判定に使う文字列
  int n;     //Sの文字長

  while(true) {     //
    n = S.size();     //Sの文字長を先に取得
    if(n == 0) {     //Sの文字長が0、すなわちSが全て4単語でできていたらYES
      cout << "YES" << endl;
      return 0;
    }
    
    a = n>=5 ? S.substr(n-5, 5) : "";
    //5文字以上なら末尾5文字切り取る。5文字に足らなかったら空の文字列とする
    b = n>=6 ? S.substr(n-6, 6) : "";
    c = n>=7 ? S.substr(n-7, 7) : "";
    

    if(a=="dream" || a=="erase"){
      //5文字の末尾がdreamまたはeraseに一致していれば末尾5文字削る
      S.erase(n-5, 5);
    }else if(b=="eraser"){
      S.erase(n-6, 6);
    }else if(c=="dreamer"){
      S.erase(n-7, 7);
    }else{
      cout<<"NO"<<endl;
      return 0;
    }
  }

  return 0;
}
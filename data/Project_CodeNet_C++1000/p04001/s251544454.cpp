#include <bits/stdc++.h>
using namespace std;

//ビット列から式を計算する
long long pplus(bitset<9> o,string S){
  char* s = 0;
  long long M;
  if (o == 0){
    //cout << stoi(S) << endl;
    istringstream iss(S);
    iss >> M;
   return M; 
  }
  //oとSから和を作る
  long long sum = 0;
  int front = -1;
  for (int i = 0;i<9;i++){
    M = 0;
    //何文字取り出すか変数
    int a = 0;
    //
    //cout << "this is i ";
    //cout << i << endl;
    //
   int j = 8 -i;
    //
    //cout << "this is j ";
    //cout << j << endl;
    //
    if (o.test(j)){
      //何文字取り出すか
       a = i - front;
      //
      //cout << "SUM!! -->" << to_string(sum) + " + " + S.substr(front+1,a) + "= ";
      //
      istringstream iss(S.substr(front+1,a));
      iss >> M;
       sum = sum + M;
      //cout << sum << endl;
      front = i;
      //
      //cout << "=" << sum << endl;
      //
      }
      if (i == 8){
        //cout << "SUM!! -- > ";
        //cout << sum << " + " + S.substr(front+1) + "= ";
        istringstream iss(S.substr(front+1));
        iss >> M;
       sum = sum +  M;
        //cout << sum << endl;
    }    
  }
  //cout << sum << endl;
  return sum;
}
 
int main() {
  // ここにプログラムを追記
  long long sum;
  string S;
  cin >> S;
  int l = S.size();
  while (S.size() < 10){
   S = "0" + S; 
  }
  for (int i = 0;i < (1 << (l-1));i++){
    bitset<9> s(i);
    sum += pplus(s,S);
  }
  
  cout << sum << endl;
}
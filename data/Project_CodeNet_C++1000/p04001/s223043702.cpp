#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
  string S;
  cin >> S;
 
  int N = (int)S.size();
 
  //求める合計
  long long total = 0;
 
  //1つの式の値
  long long value;
  string smemo;
 
  for( int tmp = 0; tmp < ( 1<<(N-1) ); tmp++){
    
      //初期値
      value = 0;
      smemo = "";
      smemo += S[0];
      for( int i = 0; i < N-1; i++){
         
         if( tmp & (1<<i) ){
            value += stol(smemo);
            smemo = "";
         }
        smemo += S[i+1];
      }
      value += stol(smemo);
      total += value;
  }
 
  cout << total << endl;
  return 0;
 
}
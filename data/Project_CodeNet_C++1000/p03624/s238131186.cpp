#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int N = S.size();
  
  bool exist[26];
  for(int i=0; i<26; i++) exist[i]= false;
  
  //文字列に各アルファベットがあるか探索．あればexistの対応する要素がtrue
  char s = 'a';
  for(int i=0; i<26; i++){
    for(int j=0; j<N; j++){
      if(S[j] == s) exist[i] = true;
    }
    s = (char)(s+1);//探索対象の文字を次のアルファベットへ
  }
  
  bool None = false;
  for(int i=0; i<26; i++){
    if (exist[i] == false){
      None = true;
      cout << (char)(i+'a') << endl;
      break;
    }
  }
  
  if (None == false) cout << "None" << endl;
      
}
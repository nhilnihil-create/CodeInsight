#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T="";
  cin >> S;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='0'){
      T.push_back('0');
    }
    else if(S.at(i)=='1'){
      T.push_back('1');
    }
    else if(T.size()){
      T.pop_back();
    }
  }
  cout << T << endl;
}
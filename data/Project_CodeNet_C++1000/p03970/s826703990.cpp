#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T="CODEFESTIVAL2016";
  cin >> S;
  int count=0;
  for(int i=0;i<S.size();i++){
    if(S.at(i)!=T.at(i)){
      count++;
    }
  }
  cout << count << endl;  
}
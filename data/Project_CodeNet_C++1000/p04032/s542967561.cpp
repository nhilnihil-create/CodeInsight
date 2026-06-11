#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int N=S.size();
  bool a=false;
  for(int i=0;i<N-1;i++){
    string T=S.substr(i,2);
    if(T.at(0)==T.at(1)){
      a=true;
      cout << i+1 << " " << i+2 << endl;
      break;
    }
    if(i!=N-2){
      string U=S.substr(i,3);
      if(U.at(0)==U.at(2)){
        a=true;
        cout << i+1 << " " << i+3 << endl;
        break;
      }
    }
  }
  if(!a){
    cout << -1 << " " << -1 << endl;
  }
}   
#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  string T = S;
  reverse(T.begin(),T.end());
  bool flag = true;
  for(int i=0; i<S.size(); i++){
    if(T.at(i) == 'b'){
      if(S.at(i) != 'd'){
        flag = false;
      }
    }
    if(T.at(i) == 'd'){
      if(S.at(i) != 'b'){
        flag = false;
      }
    }
    if(T.at(i) == 'p'){
      if(S.at(i) != 'q'){
        flag = false;
      }
    }
    if(T.at(i) == 'q'){
      if(S.at(i) != 'p'){
        flag = false;
      }
    }
  }
  if(flag){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
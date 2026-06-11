#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  set<char> s;
  for(int i=0;i<S.size();i++){
    s.insert(S.at(i));
  }
  for(auto x:s){
    if(x=='N'){
      if(!s.count('S')){
        cout << "No" << endl;
        return 0;
      }
    }else if(x=='S'){
      if(!s.count('N')){
        cout << "No" << endl;
        return 0;
      }
    }else if(x=='E'){
      if(!s.count('W')){
        cout << "No" << endl;
        return 0;
      }
    }else{
      if(!s.count('E')){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}

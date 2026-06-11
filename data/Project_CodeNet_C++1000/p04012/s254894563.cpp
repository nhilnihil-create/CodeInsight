#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  bool a=false;
  for(char C='a';C<='z';C++){
    int count=0;
    for(int i=0;i<S.size();i++){
      if(S.at(i)==C){
        count++;
      }
    }
    if(count%2==1){
      a=true;
    }
  }
  if(!a){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
} 
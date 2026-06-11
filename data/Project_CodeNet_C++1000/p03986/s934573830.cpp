#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  stack<char> A;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='S'){
      A.push('S');
    }
    else if(S.at(i)=='T' && A.size()!=0 && A.top()=='S'){
      A.pop();
    }
    else{
      A.push('T');
    }
  }
  cout << A.size() << endl;
}
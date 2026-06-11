#include <bits/stdc++.h>
using namespace std;
int main(){
  string S; cin>>S;
  stack<char>A;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='0')A.push('0');
    else if(S.at(i)=='1')A.push('1');
    else if(!A.empty())A.pop();
  }
  stack<char>B;
  for(int i=0;!A.empty();i++){
    B.push(A.top());
    A.pop();
  }
  for(int i=0;!B.empty();i++){
    cout<<B.top();
    B.pop();
  }
  cout<<endl;
}
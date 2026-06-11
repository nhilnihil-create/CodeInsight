#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;
  deque<char> dq;
  int count=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='('){
      count++;
      dq.push_back('(');
    }else if(S.at(i)==')'){
      dq.push_back(')');
      if(count==0){
        dq.push_front('(');
      }else{
        count--;
      }
    }
  }
  while(count>0){
    dq.push_back(')');
    count--;
  }
  for(int i=0;i<dq.size();i++){
    cout << dq.at(i);
  }
  cout << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;
  string ans="";
  int count=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='('){
      count++;
      ans.push_back('(');
    }else if(S.at(i)==')'){
      ans.push_back(')');
      if(count==0){
        ans.insert(ans.begin(),'(');
      }else{
        count--;
      }
    }
  }
  while(count>0){
    ans.push_back(')');
    count--;
  }
  cout << ans << endl;
  return 0;
}

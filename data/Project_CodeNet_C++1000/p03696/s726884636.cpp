#include <iostream>
#include <stack>

using namespace std;

int main(){
  int N, r=0;
  string S;
  stack<char> s;
  cin >> N >> S;

  for (int i = 0; i < N; i++){
    if(S[i] == '('){
      s.push('(');
    }else{
      if(s.empty() == 0){
        s.pop();
      }else{
        r++;
      }
    }
  }

  for (int i = 0; i < r; i++){
    S.insert(S.begin(),'(');
  }
  
  for (int i = 0; i < s.size(); i++){
    S.insert(S.end(),')');
  }
  
  printf("%s\n",S.c_str());
}

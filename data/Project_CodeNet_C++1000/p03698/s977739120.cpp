#include <iostream>
#include <string>

using namespace std;

int main(){
  string S;
  int flg=0;
  cin >> S;
  for (int i = 0; i < S.size() - 1; i++){
    for (int j = i+1; j < S.size(); j++){
      if (S[i]==S[j]){
        flg = 1;
      }
    }
  }
  if (flg==1){
    printf("no\n");
  }else{
    printf("yes\n");
  }
  
  
}

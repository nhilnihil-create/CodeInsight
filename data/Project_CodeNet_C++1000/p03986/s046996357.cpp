#include <iostream>
#include <string>

using namespace std;

int main(){
  string S;
  cin >> S;
  int s=0,ans=0;
  for (int i = 0; i < (int)S.size(); i++){
    if(s == 0 && S[i] == 'T'){
      ans++;
    }else if(S[i] == 'S'){
      s++;
    }else if(S[i] == 'T'){
      s--;
    }
  }

  printf("%d\n", ans + s);
  
}

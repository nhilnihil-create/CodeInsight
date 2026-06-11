#include <iostream>
#include <string>

using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;
  int ans=0, n=0;
  for (int i = 0; i < N; i++){
    if (S[i]=='I'){
      n++;
    }else{
      n--;
    }
    if (n > ans){
      ans = n;
    }
    
  }
  
  printf("%d\n", ans);
}

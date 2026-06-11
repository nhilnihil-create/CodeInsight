#include <iostream>
using namespace std;

int main(){
  int K, S;
  cin >> K >> S;
  int ans = 0;
  for(int A=0; A<=K; A++){
    for(int B=0; B<=K; B++){
      if(0<=S-A-B && S-A-B<=K){
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
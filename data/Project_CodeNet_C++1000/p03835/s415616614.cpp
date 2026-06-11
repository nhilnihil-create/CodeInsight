#include <iostream>
using namespace std;

int main(){
  int K,S;
  cin >> K >> S;
  int ans = 0;
  for(int X=0; X<=K; X++){
    for(int Y=0; Y<=K; Y++){
      int m = S-X-Y;
      if(0<=m && m<=K){
          ans++;
        }
    }
  }
  cout << ans;
  return 0;
}
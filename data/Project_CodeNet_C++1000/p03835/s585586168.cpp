#include <bits/stdc++.h>
using namespace std;

int main(){
  int K, S, X, Y, Z, ans = 0;
  cin >> K >> S;
  
  for (X = 0; X <= K; X++){
    for (Y = X; Y <= K; Y++){
      for (Z = Y; Z <= K; Z++){
        if (X + Y + Z != S){
          continue;
        }
        
        if (X == Y && Y == Z){
          ans += 1;
        }
        else if(X == Y || Y == Z || Z == X){
          ans += 3;
        }
        else{
          ans += 6;
        }
      }
    }
  }
  
  cout << ans << endl;
  
}
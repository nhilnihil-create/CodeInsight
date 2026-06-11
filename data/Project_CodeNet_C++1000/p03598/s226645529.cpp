#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  
  int ans = 0;
  for (int i = 0; i < N; i++){
    int X;
    cin >> X;
    
    if (X <= K / 2){
      ans += X * 2;
    }
    else{
      ans += (K - X) * 2;
    }
    
  }
  
  cout << ans << endl;
}
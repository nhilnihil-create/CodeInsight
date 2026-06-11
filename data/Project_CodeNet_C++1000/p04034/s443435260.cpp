#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<int> BALL(N, 1);
  vector<bool> RED(N, false);
  RED.at(0) = true;
  
  for (int i = 0; i < M; i++){
    int X, Y;
    cin >> X >> Y;
    X -= 1;
    Y -= 1;
    
    if (RED.at(X) == true){
      RED.at(Y) = true;
    }
    
    BALL.at(X)--;
    BALL.at(Y)++;
    
    if (BALL.at(X) <= 0){
      RED.at(X) = false;
    }
  }
  
  int ans = 0;
  for (int i = 0; i < N; i++){
    if (RED.at(i) == true){
      ans++;
    }
  }

  
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, K, X, Y;
  Y = 0;
  cin >> N >> K; 
  for(int i = 0;i < N;i++){
   cin >> X;
   if(X * 2 > (K - X) * 2){
    Y = Y + (K - X);
   }else{
    Y = Y + X;
   }
  }
  cout << Y * 2 << endl;
}
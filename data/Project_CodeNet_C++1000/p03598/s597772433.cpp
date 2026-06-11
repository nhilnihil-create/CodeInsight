#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, K;
  int sum = 0;
  cin >> N;
  cin >> K;
  rep(i, N){
  int X;
  cin >> X;
  if(X <= K){
   if(X <= K - X){
    sum += X * 2;
     }else{
    sum += (K - X) * 2;}
    }
  if(X > K){
    sum += (X - K) * 2;
   }
  }
  cout << sum <<endl;
  return 0;
}
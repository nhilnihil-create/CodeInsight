#include <iostream>
using namespace std;

int main(){
  int N,K;
  int i = 0;
  int sum = 0;
  cin >> N >> K;
  
  int A = 0; //タイプAの総移動距離
  int B = 0; //タイプBの総移動距離
  
  for(i = 0;i < N; i++){
    int x;
    cin >> x;
    
    A = 2 * x;
    B = 2 * (K - x);
    if (A < B){
      sum += A;
    }
    else{
      sum += B;
    }
  }
  cout << sum << endl;
}
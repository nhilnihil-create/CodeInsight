#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, sum;
  sum = 0;
  cin >> N >> K;
  
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    
    if(x < K){
      if(x < (K-x) || x == (K-x)){
        sum += x*2;
      }
      else if(x > (K-x)){
        sum += (K-x)*2;
      }
    }
    
    else if(x > K){
      if(K < (x-K) || K == (x-K)){
        sum += K*2;
      }
      else if(K > (x-K)){
        sum += (x-K)*2;
      }
    }
  }
  cout << sum << endl;
}
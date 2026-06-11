#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K, x, sum=0;
  cin >> N >> K;
  
  for(int i=0; i<N; i++){
    cin >> x;
    if(abs(K-x) > x)
      sum += 2*x;
    else sum += 2*abs(K-x);
  }
  cout << sum;
}
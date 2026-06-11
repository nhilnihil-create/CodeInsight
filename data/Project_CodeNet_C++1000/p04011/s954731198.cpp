#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,K,X,Y,a;
  cin >> N;
  cin >> K;
  cin >> X;
  cin >> Y;
  
  if(N<K){
    a=X*N;
  }else{
    a=X*K+Y*(N-K);
  }
  cout << a << endl;
  
}
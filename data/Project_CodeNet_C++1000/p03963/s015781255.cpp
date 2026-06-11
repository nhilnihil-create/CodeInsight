#include<bits/stdc++.h>
using namespace std;
  
int main(){
  int N,K;
  cin >> N >> K;
  int S = K;
  for(int i = 1; i<N; i++){
    S *= (K-1);
  }
  
  cout << S << endl;
  
}
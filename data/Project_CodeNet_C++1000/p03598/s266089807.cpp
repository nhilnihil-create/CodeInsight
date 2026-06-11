#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,i = 0;
  cin >> N >> K;
  for (int k = 0; k < N; k++){
    int S;
    cin >> S;
    if (K - S < S){
      i += (K - S) * 2;
    }else{
      i += S * 2; 
    }
  }
    cout << i << endl;
}
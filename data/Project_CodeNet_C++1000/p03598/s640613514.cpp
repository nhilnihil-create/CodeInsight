#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K, D=0, d;
  cin >> N >> K;
  for (int i=0; i<N; i++){
    cin >> d;
    if (d <= K-d){
      D += d;
    } else{
      D += K-d;
    }
  }
  cout << D*2 <<endl;
}
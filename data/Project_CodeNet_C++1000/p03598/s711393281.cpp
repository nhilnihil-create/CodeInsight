#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  int a,b;
  b = 0;
  cin >> N >> K;
  
  
  for (int i=0;i < N;i++){
    cin >> a;
    if (K-a >= a){
      b = b + (a * 2);
    }
    if (K-a < a){
      b = b + (K - a) * 2;
    }
  }  
  cout << b << endl;
}

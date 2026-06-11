#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K, x, y, z, a = 0;
  cin >> N >> K;
  for (int i = 0; i < N; i++){
    cin >> x;
    y = x * 2;
    z = abs(K - x) * 2;
    if(y < z){
      a += y;
    }
    else{
      a += z;
    }
  }
  cout << a << endl;
}
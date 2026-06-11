#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, K;
  cin >> N >> K;
  int x, y = 0;
  
  for (int i = 0;N > i;i++){
    cin >> x;
    if (K / 2 < x){
      y += (K - x) * 2;
    }
    else{
      y += x * 2;
    }
  }
  cout << y << endl;
}
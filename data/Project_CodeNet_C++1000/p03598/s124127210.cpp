#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,x,y;
  cin >> N >> K;
  y = 0;
  
  for(int i = 0; i < N; i++){
    cin >> x;
    if(K - x > x)  y = y + 2 * x;
    if(K - x <= x) y = y + 2 * (K - x);
  }
  cout << y << endl; 
}
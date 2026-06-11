#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  const int mod = 1000000007;
  long power = 1;
  
  for (int i = 0 ; i < N ; i++ ){
    power = power * (i+1) % mod;
  }
  
  cout << power;
}
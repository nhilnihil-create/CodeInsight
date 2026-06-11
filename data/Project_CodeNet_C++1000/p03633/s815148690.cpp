#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N;
  
  vector<int64_t> vec(N);
  
  for (int i = 0; i < N; i++) cin >> vec[i];
  
  if (N == 1) { cout << vec[0] << endl; return 0; }
  
  int64_t tmp = vec[0] / __gcd(vec[0], vec[1]) * vec[1];
  
  for (int i = 2; i < N; i++) tmp = tmp / __gcd(tmp, vec[i]) * vec[i];
  
  cout << tmp << endl;
  
}
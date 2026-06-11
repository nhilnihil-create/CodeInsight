#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int N;
  cin >> N;
  
  int64_t p = 1;
  int64_t f = 1000000007;
 
  for (int i = 1; i <= N; i++) {
    p = p * i;
    p = p % f;
  }
  
  cout << p << endl;
 
}
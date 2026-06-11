#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  char sign;
  char current = '=';
  int ans = 1;
  
  for (int i = 1; i < N; i++){
    if (A.at(i) > A.at(i-1)) sign = '+';
    else if (A.at(i) < A.at(i-1)) sign = '-';
    else continue;
    
    if (sign != current && current != '='){
      ans++;
      current = '=';
      continue;
    }
    
    current = sign;
  }
  
  cout << ans << endl;  
}
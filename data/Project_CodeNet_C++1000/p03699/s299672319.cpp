#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int sum = 0;
  
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++) cin >> vec[i];
  
  sort(vec.begin(), vec.end());
  
  for (int x : vec) sum += x;
  
  if (sum % 10 != 0) { cout << sum << endl; return 0; }
  
  for (int i = 0; i < N; i++) {
    
    int tmp = vec[i];
    
    if (tmp % 10 != 0) { cout << sum - tmp << endl; return 0; }
    
  }
  
  cout << 0 << endl;
  
}
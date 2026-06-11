#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int64_t sum = 0;
  
  vector<int> vec(N * 3);
  
  for (int i = 0; i < N * 3; i++) cin >> vec[i];
  
  sort(vec.begin(), vec.end());
  
  int numCenter = N * 3 - 2; int count = 0;
  
  while (true) {
    
    sum += vec[numCenter];
    
    numCenter -= 2; count++;
    
    if (count == N) break;
    
  }
  
  cout << sum << endl;
  
}
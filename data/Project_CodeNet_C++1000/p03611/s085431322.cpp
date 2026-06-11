#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int ans = 0;
  
  vector<int> vec(pow(10, 5), 0);
  
  for (int i = 0; i < N; i++) {
    
    int a; cin >> a; vec[a]++;
    
  }
  
  for (int i = 1; i < vec.size() - 1; i++) {
    
    int tmp = vec[i - 1] + vec[i] + vec[i + 1];
    
    ans = max(ans, tmp);
    
  }
  
  cout << ans << endl;
  
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> kusi(2 * n);
  
  for (int i = 0; i < n; i++){
    cin >> kusi.at(2 * i) >> kusi.at(2 * i + 1);
  }
  
  sort(kusi.begin(), kusi.end());
  
  int ans = 0;
  
  for (int i = 0; i < n; i++){
    
    ans += min(kusi.at(2 * i), kusi.at(2 * i + 1));
    
  }
  
  cout << ans << endl;
  
}


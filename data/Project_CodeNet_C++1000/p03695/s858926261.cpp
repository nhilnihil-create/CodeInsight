#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int count = 0, anyColor = 0;
  
  vector<bool> vec(8, false);
  
  for (int i = 0; i < N; i++) {
    
    int a; cin >> a;
    
    int tmp = a / 400;
    
    if (tmp < 8) vec[tmp] = true;
    
    else anyColor++;
    
  }
  
  for (bool flag : vec) if (flag) count++;
  
  cout << max(count, 1) << " " << count + anyColor << endl;
  
}
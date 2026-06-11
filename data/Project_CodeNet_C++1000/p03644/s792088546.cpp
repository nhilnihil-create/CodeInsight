#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int maxcount = 0;
  int ans = 1;
  for (int i = 1; i <= N; i++) {
    int x = i;
    int count = 0;
    
    while (x % 2 == 0) {
      count++;
      x /= 2;
    }
    
    if (count > maxcount) {
      maxcount = count;
      ans = i;
    }
  }
  
  
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N ;
  
  int ans;
  ans = 0;
  
  for (int i = 0; i < N; i++) {
    int li , ri;
      cin >> li >> ri;
    
    
    ans += ri - li;
  }
  
  ans += N; 
  cout << ans << endl;
}

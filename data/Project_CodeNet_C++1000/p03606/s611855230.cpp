#include <bits/stdc++.h>
// #include<atcoder/all>
using namespace std;
// using namespace atcoder;

int main() {
    int N, s, e;
    cin >> N;
    int ans = 0;
    for(int i = 0;i<N ; i++) {
      cin >> s >> e;
      ans += e-s+1;
    }
  
  cout << ans << endl; 
  return 0;
}

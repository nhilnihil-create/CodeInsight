#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  string op;
  int ans=0;
  cin >> N >> op >> M;
  if (op=="+"){
    ans = N+M;
  }else{
    ans = N-M;
  }
  
  cout << ans << endl;
  return 0;
}
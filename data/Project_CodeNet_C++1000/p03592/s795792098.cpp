#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, k;
  cin >> n >> m >> k;
  
  bool ok = false;
  for(int i = 0; i <= n; i++){
    int cnt = k - i * m;
    if(n-i*2 == 0){
      if(cnt == 0){
        ok = true;
      }
      continue;
    }
    if(cnt%(n-i*2) == 0){
      int l = cnt/(n-i*2);
      if(l <= m && l >=0) ok = true;
    }
  }
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
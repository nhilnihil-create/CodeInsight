#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int a = 0, b = 0;
  for(int i = 0; i < n; i++){
    int c; cin >> c;
    if(c % 4 == 0){
      a++;
      continue;
    }
    if(c % 2 == 1){
      b++;
      continue;
    }
  }
  bool ok = true;
  if(b > a + 1) ok = false;
  if(b == a + 1 && n - b - a > 0) ok = false;
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
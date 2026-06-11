#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  int tmp;
  bool chk = false;
  
  cin >> a >> b >> c;
  
  for(int i = 1; i <= a*b; i++){
    if(a*i % b == c){
      chk = true;
      break;
    }
  }
  
  if(chk == true) cout << "YES";
  else cout << "NO";
}

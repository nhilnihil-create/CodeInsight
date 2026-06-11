#include <bits/stdc++.h>
using namespace std;

int main() {
  bool chk = false;
  int a,b;
  cin >> a >> b;
  
  if(a % 3 == 0){
   chk = true; 
  }else if(b % 3 == 0){
    chk = true; 
  }else if((a + b) % 3 == 0){
    chk = true;
  }
  
  if(chk == true) cout << "Possible";
  else cout << "Impossible";
}

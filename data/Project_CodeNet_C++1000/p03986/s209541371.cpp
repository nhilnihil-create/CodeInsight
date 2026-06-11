#include <bits/stdc++.h>
using namespace std;

int main(){
  string x;
  cin >> x;
  
  int l = x.size();
  int ans = 0, erase = 0;
  for(int i = 0; i < l; i++){
    char now = x.at(i);
    if(now == 'S') erase--;
    else{
      if(erase >= 0) ans += 2;
      if(erase < 0) erase++;
    }
  }
  
  cout << ans << endl;
}
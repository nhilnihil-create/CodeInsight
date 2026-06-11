#include <bits/stdc++.h>
using namespace std;


int main(){
  int a,b;
  cin >> a >> b;
  int ans;
  for (int i = 0; i < a; i++){
    if (i == 0){
      ans += b;
    }
    else{
      ans = ans * (b - 1);
    }
  }

  cout << ans << endl;
    
}
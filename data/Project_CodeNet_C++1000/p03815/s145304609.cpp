#include <iostream>

using namespace std;

int main(){
  long long x, ans;

  cin >> x;
    
  ans = x / 11 * 2;
  x %= 11;

  if(x <= 6 && x > 0){
      cout << ans + 1 << endl;
  }else if(x > 6){
      cout << ans + 2 << endl;
  }else{
      cout << ans << endl;
  }
}
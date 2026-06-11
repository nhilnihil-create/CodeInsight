#include <iostream>
#include <math.h>
using namespace std;

void solve(){
  long W,a, b;
  cin >> W >> a >> b ;
  long ans =0;
  if((a + W) < b) {
    ans = b - (a + W);
  }else if((b + W) < a){
    ans = a - (b+W);
  }
  std::cout << ans;
}


int main() {
  solve();
}


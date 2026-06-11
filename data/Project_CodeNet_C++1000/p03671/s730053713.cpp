#include <iostream>

using namespace std;

int main(){
  int a,b,c,ans;
  cin >> a >> b >> c;
  ans = min(a+b,a+c);
  ans = min(ans,b+c);
  cout << ans;
}

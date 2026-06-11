#include <iostream>
using namespace std;

int main(){
  int X,t,ans;
  cin >> X >> t;
  ans=(X<t)? 0:X-t;
  cout << ans << endl;
}
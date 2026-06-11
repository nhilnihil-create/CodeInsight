#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int a,b,w;
  cin >> w >> a >> b;
  if(max(a+w-b,b+w-a)<=2*w) cout << 0 << "\n";
  else cout << min(abs(a-b-w),abs(b-a-w)) << "\n";
  return 0;
}
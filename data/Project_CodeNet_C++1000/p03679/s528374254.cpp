#include <iostream>
using namespace std;
int main(){
  int x,a,b;
  cin >> x >> a >> b;
  if(a-b>=0) cout << "delicious" << "\n";
  else if(abs(a-b)<=x) cout << "safe" << "\n";
  else cout << "dangerous" << "\n";
  return 0;
}                                                                                       
#include <iostream>
using namespace std;

void solve(){
  int a, b; cin >> a >> b;
  if(a == b) cout << "Draw" << endl;
  else if(a == 1 || (a > b && b != 1)) cout << "Alice" << endl;
  else cout << "Bob" << endl;
}

int main(){
  solve();
  return 0;
}
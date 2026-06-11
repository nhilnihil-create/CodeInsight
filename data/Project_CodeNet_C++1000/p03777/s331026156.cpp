#include<bits/stdc++.h>
using namespace std;
bool PN(int x) {
  if (x <= 1) return false;
  if (x == 2) return true;
  for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false;
  return true;
}

void solve(){
  char a, b; cin >> a >> b;
  if(a == b) cout << 'H' << endl;
  else cout << 'D' << endl;
  
}

int main(){
  solve();
  return 0;
}
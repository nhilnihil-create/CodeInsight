#include<bits/stdc++.h>
using namespace std;
bool PN(int x) {
  if (x <= 1) return false;
  if (x == 2) return true;
  for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false;
  return true;
}

void solve(){
  int w, a, b;
  cin >> w >> a >> b;
  if(abs(b-a) <= w) cout << 0 << endl;
  else {
    cout << abs(b-a)-w << endl;
  }
}

int main(){
  solve();
  return 0;
}
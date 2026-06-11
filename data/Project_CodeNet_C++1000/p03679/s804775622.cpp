#include<bits/stdc++.h>
using namespace std;
int main() {
  int x, a, b; cin >> x >> a >> b; string s;
  if(b - a <= 0) s = "delicious";
  else if(b - a <= x) s = "safe";
  else s = "dangerous";
  cout << s << endl;
}

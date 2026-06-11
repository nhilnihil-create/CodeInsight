#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  int ans = 0;
  
  if (a==b) ans++;
  if (b==c) ans++;
  if (a==c) ans++;
  
  if (ans==3) cout << 1 << endl;
  if (ans==1) cout << 2 << endl;
  if (ans==0) cout << 3 << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  long long ans = 0;
  bool ok = true;
  if(a == b && b == c && c == a && a%2 == 0) ok = false, ans = -1;
  if(a%2 || b%2 || c%2) ok = false;
  while(ok){
    int na = (b+c) / 2, nb = (c+a) / 2, nc = (a+b) / 2;
    a = na, b = nb, c = nc;
    if(a%2 || b%2 || c%2) ok = false;
    ans++;
  }
  
  cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main(void){
  int a, b, c;
  int cnt = 3;
  cin >> a >> b >> c;
  if(a == b && b == c)
    cnt = 1;
  else if(a == b || b == c || a == c)
    cnt = 2;
  cout << cnt << "\n";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t a, b, x, tmp1, tmp2;
  cin >> a >> b >> x;
  if(a==0)
    tmp1=0;
  else tmp1=(a-1)/x+1;
  tmp2=b/x+1;
  cout << tmp2-tmp1;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
using lli = long long;
lli A, B, C, a, b, c;

int main(void){
  cin >> A >> B >> C;
  a = A;
  b = B;
  c = C;
  int res = 0;
  while(a%2 == 0 && b%2 == 0 && c%2 == 0){
    lli na, nb, nc;
    na = b/2 + c/2;
    nb = c/2 + a/2;
    nc = a/2 + b/2;
    a = na;
    b = nb;
    c = nc;
    res++;
    if(res >= 50){
      res = -1;
      break;
    }
  }
  cout << res << endl;
  return 0;
}

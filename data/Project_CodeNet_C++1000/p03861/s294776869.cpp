#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(void) {
  ll a, b ,x;
  cin >> a >> b >> x;
  if(a==0)
  cout << (b/x)-(-1) << endl;
  else
  cout << (b / x) - ((a-1)/x) << endl;
}
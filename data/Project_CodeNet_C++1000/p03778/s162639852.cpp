#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main(void) {
  int w, a, b;
  cin >> w >> a >> b;
  if(b > a+w)
  cout << b-(a+w) << endl;
  else if(a > b+w)
  cout << a-(b+w) << endl;
  else 
  cout << 0 << endl;
}
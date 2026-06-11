#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(void) {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b && b == c)
  cout << 1 << endl;
  else if (a == b || b == c || c == a)
  cout << 2 << endl;
  else
  {
    cout << 3 << endl;
  }
  
  
}
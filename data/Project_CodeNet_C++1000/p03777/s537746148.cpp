#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main(void) {
  char a, b;
  cin >> a >> b;
  if(a=='H') {
    cout << b << endl;
  } else {
    if(b=='H')
    cout << "D" << endl;
    else 
    cout << "H" << endl;
  }
}
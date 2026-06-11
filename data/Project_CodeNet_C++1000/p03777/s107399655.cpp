#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  char a, b;
  cin >> a >> b;
  if(a == 'D') {
    if(b == 'H') cout << 'D' << endl;
    else cout << 'H' << endl;
  }
  else {
  if(b == 'H') cout << 'H' << endl;
  else cout << 'D' << endl;
  }
}
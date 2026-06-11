#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if(abs(x - a) > abs(x - b)) cout << 'B' << endl;
  else cout << 'A' << endl;
}
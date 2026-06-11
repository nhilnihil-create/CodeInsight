#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if(b <= a) cout << "delicious" << endl;
  else if(a < b && b <= x+a) cout << "safe" << endl;
  else if(a+x < b) cout << "dangerous" << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int cnt = 0;
  if(a == b && b == c) cnt = 1;
  else if(a != b && b != c && a != c) cnt = 3;
  else cnt = 2;
  cout << cnt << endl;
}
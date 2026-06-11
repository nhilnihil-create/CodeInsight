#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  bool flag = false;
  if(b - a == c - b) flag = true;
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}
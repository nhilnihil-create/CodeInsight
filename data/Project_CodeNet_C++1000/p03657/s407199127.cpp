#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int a, b;
  cin >> a >> b;
  bool flag = true;
  if(a % 3 != 0 && b % 3 != 0 && (a+b) % 3 != 0) {
    flag = false;
  }
  
  if(flag) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}